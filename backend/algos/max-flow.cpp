
//#include "stdafx.h"
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define all(c) c.begin(), c.end()
#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(c) int((c).size())
#define NAME = "flow"
#define FREOPEN                      \
    freopen(NAME ".in", "r", stdin); \
    freopen(NAME ".out", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll N = 5e5 + 9, M = 2e3 + 11, INF = 1e9 + 7, INF64 = 1e15 + 7;
const ld EPS = 1e-10;

struct edge
{
    edge() {}
    edge(int to, int c, int f) : to(to), c(c), f(f) {}
    int to, c, f;
};

int n, m, cnt;
vector<pii> m_edges;
vector<int> order;
edge e[N];
vector<vector<pii>> g(N);
bool mark[N];

bool dfs(int v = 0)
{
    bool cur = false;
    if (v == n - 1)
        return true;
    mark[v] = true;
    for (auto to : g[v])
        if (!mark[to.x] && e[to.y].f < e[to.y].c && !cur)
        {
            if (dfs(to.x))
            {
                order.pb(to.y);
                cur = true;
            }
        }
    return cur;
}

int main(int argc, char **argv)
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

    int x, y, c;
    ll s = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> m;
    forn(i, m)
    {
        cin >> x >> y >> c;
        x--;
        y--;
        e[++cnt] = edge(y, c, 0);
        //m_edges.pb(mp(cnt, true));
        e[N - cnt] = edge(x, c, 0);
        g[x].pb(mp(y, cnt));
        g[y].pb(mp(x, N - cnt));
    }

    while (dfs())
    {
        int cf = INF;

        for (auto ind : order)
        {
            cf = min(cf, e[ind].c - e[ind].f);
            //cout << e[ind].to + 1 << " ";
        }
        //cout << endl;
        for (auto ind : order)
        {
            e[ind].f += cf;
            e[N - ind].f -= cf;
        }
        order.clear();
        forn(i, n)
            mark[i] = false;
    }
    for (auto x : g[0])
        s += e[x.y].f;
    cout << fixed << setprecision(10) << ld(s) << endl;
    for (int i = 1; i <= m; i++)
        cout << ld(e[i].f) << endl;

    cout << endl;
    return 0;
}
