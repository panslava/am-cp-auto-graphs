#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <array>
#include <cmath>
#include <deque>
#include <unordered_set>
#include <fstream>
#include <random>
#include <numeric>
#include <functional>
#include <queue>
#include <set>
#include <map>

#pragma comment(linker, "/STACK:66777216")

std::vector<std::unordered_map<int, int>> conj_list, back_list;

std::vector<int> out_time;
std::vector<bool> used;
std::vector<int> colors;

int n_time = 0;
int color = -1;

void connectivity(int v)
{
    if (used[v])
        return;
    used[v] = true;
    for (auto &u : conj_list[v])
        connectivity(u.first);
}

void back_dfs(int v)
{
    if (used[v])
        return;
    used[v] = true;

    for (auto &u : back_list[v])
        if (u.second == 0)
            back_dfs(u.first);

    out_time[v] = n_time++;
}

void dfs(int v)
{
    if (used[v])
        return;
    used[v] = true;
    colors[v] = color;

    for (auto &u : conj_list[v])
        if (u.second == 0)
            dfs(u.first);
}

bool is_acyclic(int v)
{
    if (used[v])
        return false;
    used[v] = true;

    for (auto &u : conj_list[v])
        if (u.second == 0)
            if (!is_acyclic(u.first))
                return false;

    return true;
}

long long do_thing(int root, int n)
{
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        int mn = 2e9 + 2;
        for (auto &j : back_list[i])
            mn = std::min(mn, j.second);

        for (auto &j : back_list[i])
            j.second -= mn, conj_list[j.first][i] -= mn;
        if (i != root)
            res += mn;
    }

    used.assign(n, false);
    is_acyclic(root);
    if (std::accumulate(used.begin(), used.end(), 0) == n)
        return res;

    auto ucopy = used;

    out_time.assign(n, 0);
    used.assign(n, false);
    colors.assign(n, -1);
    color = -1;

    for (int i = 0; i < n; i++)
        if (!used[i])
            back_dfs(i);
    used.assign(n, false);

    std::vector<int> order(n);

    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [](const int a, const int b) { return out_time[a] > out_time[b]; });

    for (auto &i : order)
    {
        if (!used[i])
        {
            color++;
            dfs(i);
        }
    }
    order.clear();

    for (int i = 0; i < n; i++)
        if (ucopy[i])
            colors[i] = colors[root];

    auto newcls = std::set<int>(colors.begin(), colors.end());
    std::unordered_map<int, int> ncls_map;
    for (auto &i : newcls)
        ncls_map.emplace(i, ncls_map.size());

    color = ncls_map.size() - 1;

    for (auto &i : colors)
        i = ncls_map[i];
    ncls_map.clear();
    ucopy.clear();
    newcls.clear();

    long long sm = 0;
    std::vector<std::unordered_map<int, int>> ncnj_list(color + 1), nbcl_list(color + 1);

    for (int i = 0; i < n; i++)
        for (auto &j : conj_list[i])
            if (colors[i] != colors[j.first] && colors[j.first] != colors[root])
            {
                int mn = j.second;
                if (ncnj_list[colors[i]].count(colors[j.first]))
                    mn = std::min(ncnj_list[colors[i]][colors[j.first]], mn);

                ncnj_list[colors[i]][colors[j.first]] = mn;
                nbcl_list[colors[j.first]][colors[i]] = mn;
            }

    conj_list = std::move(ncnj_list), back_list = std::move(nbcl_list);

    return res + do_thing(colors[root], color + 1);
}

int main(int argc, char **argv)
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (argc < 3)
    {
        std::cerr << "ERROR: Enter input and ouput file" << std::endl;
        return 1;
    }
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);

    long long res = 0;
    int n, m;
    std::cin >> n >> m;

    conj_list.resize(n);
    back_list.resize(n);
    out_time.resize(n);
    used.resize(n);
    colors.resize(n);

    for (auto i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;

        //if (w < 0)
        //    res += w, w = 0;

        if (v != 0)
        {
            if (conj_list[u].count(v))
                w = std::min(w, conj_list[u][v]);

            conj_list[u][v] = w;
            back_list[v][u] = w;
        }
    }

    connectivity(0);
    if (std::accumulate(used.begin(), used.end(), 0) != n)
    {
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::cout << "YES" << std::endl
              << res + do_thing(0, n) << std::endl;

    return 0;
}