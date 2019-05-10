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

struct edge
{
    int u, v;
    long double w;

    bool operator<(const edge &b) const
    {
        return w < b.w;
    }
};

vector<edge> edges;
vector<ll> p;

void dsu_make(int v)
{
    p[v] = -1;
}

int dsu_get(int v)
{
    if (p[v] == -1)
        return v;
    else
        return (p[v] = dsu_get(p[v]));
}

void dsu_join(int a, int b)
{
    int u = dsu_get(a);
    int v = dsu_get(b);
    if (u == b)
        return;

    if (rand() % 2)
        p[u] = v;
    else
        p[v] = u;
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
    p.resize(n + 1);
    forn(i, n)
    {
        dsu_make(i + 1);
    }

    edges.resize(m);

    forn(i, m)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(all(edges));

    long long ans = 0;
    for (auto u : edges)
    {
        if (dsu_get(u.u) != dsu_get(u.v))
        {
            dsu_join(u.u, u.v);
            ans += u.w;
        }
    }

    cout << ans << '\n';

#ifdef DEBUG
    cerr << "\nTime: " << (double)clock() / CLOCKS_PER_SEC << endl;
#endif

    cout << endl;
    return 0;
}