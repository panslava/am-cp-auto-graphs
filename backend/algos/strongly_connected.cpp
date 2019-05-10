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

vector<vector<ll>> g;
vector<vector<ll>> h;
vector<bool> used;
vector<pair<int, int>> tout;
vector<int> comp;

int timer = 0;
void cntTout(int v)
{
    used[v] = 1;
    for (auto u : g[v])
    {
        if (!used[u])
        {
            cntTout(u);
        }
    }
    tout[v] = {timer++, v};
}

void findCmp(int v, int c)
{
    used[v] = 1;
    comp[v] = c;
    for (auto u : h[v])
    {
        if (!used[u])
        {
            findCmp(u, c);
        }
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

    int n, m;
    cin >> n >> m;

    g.resize(n);
    h.resize(n);
    used.resize(n);
    comp.resize(n);
    tout.resize(n);

    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        h[b].push_back(a);
    }

    forn(i, n)
    {
        if (!used[i])
            cntTout(i);
    }

    sort(all(tout));
    reverse(all(tout));
    fill(all(used), 0);
    int lastCol = 1;
    for (auto u : tout)
    {
        if (!used[u.second])
            findCmp(u.second, lastCol++);
    }
    cout << lastCol - 1 << '\n';
    for (auto u : comp)
    {
        cout << u << ' ';
    }

#ifdef DEBUG
    cerr << "\nTime: " << (double)clock() / CLOCKS_PER_SEC << endl;
#endif
    cout << endl;
    return 0;
}
