#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
//#include <windows.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define what_is(x) cerr << '\n' \
                        << #x << " = " << x << '\n'
#define print_arr(heh)    \
    cerr << '\n';         \
    for (auto u : heh)    \
        cerr << u << ' '; \
    cerr << '\n'
#define print_arri(heh)                  \
    cerr << '\n';                        \
    for (int i = 0; i < heh.size(); i++) \
    cerr << #heh << "[" << i << "] = " << heh[i] << '\n'
#define all(a) a.begin(), a.end()
#define int long long
#define ll long long
#define ld long double
#define DEBUG

vector<ll> cut;
vector<ll> used;
vector<vector<pair<ll, ll>>> g;
vector<ll> timeIn;
vector<ll> up;

int timer = 0;
void dfs(int v, int p)
{
    used[v] = 1;
    timeIn[v] = timer++;
    up[v] = timeIn[v];
    bool is = 0;
    int cnt = 0;
    for (auto a : g[v])
    {
        auto u = a.first;
        if (u == p)
            continue;
        if (used[u])
        {
            up[v] = min(up[v], timeIn[u]);
        }
        else
        {
            cnt++;
            dfs(u, v);
            up[v] = min(up[v], up[u]);
            if (up[u] >= timeIn[v])
                is = 1;
        }
    }
    if (v == p && cnt > 1)
    {
        cut.push_back(v);
    }
    if (v != p && is)
    {
        cut.push_back(v);
    }
}

int32_t main(int32_t argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (argc < 3)
    {
        cerr << "ERROR: Enter input and ouput file" << endl;
        return 1;
    }
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
    int n;
    cin >> n;
    used.resize(n);
    up.resize(n);
    timeIn.resize(n);
    g.resize(n);

    int m;
    cin >> m;
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    forn(i, n)
    {
        if (!used[i])
        {
            dfs(i, i);
        }
    }
    sort(all(cut));
    cout << cut.size() << '\n';
    for (auto u : cut)
    {
        cout << u + 1 << ' ';
    }

#ifdef DEBUG
    cerr << "\nTime: " << (double)clock() / CLOCKS_PER_SEC << endl;
#endif

    cout << endl;
    return 0;
}