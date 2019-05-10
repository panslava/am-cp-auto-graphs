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

const int INF = 1000 * 1000 * 1000;

struct rib
{
    int b, u, c, f;
    size_t back;
};

void add_rib(vector<vector<rib>> &g, int a, int b, int u, int c)
{
    rib r1 = {b, u, c, 0, g[b].size()};
    rib r2 = {a, 0, -c, 0, g[a].size()};
    g[a].push_back(r1);
    g[b].push_back(r2);
}

int main(int argc, char **argv)
{
    cin.tie(0);

    if (argc < 3)
    {
        std::cerr << "ERROR: Enter input and ouput file" << std::endl;
        return 1;
    }
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<rib>> g(n);
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    for (int i = 0; i < m; i++)
    {
        int a, b, u, c;
        cin >> a >> b >> u >> c;
        a--;
        b--;
        add_rib(g, a, b, u, c);
    }
    int flow = 0,
        cost = 0;
    while (flow < k)
    {
        vector<int> id(n, 0);
        vector<int> d(n, INF);
        vector<int> q(n);
        vector<int> p(n);
        vector<size_t> p_rib(n);
        int qh = 0, qt = 0;
        q[qt++] = s;
        d[s] = 0;
        while (qh != qt)
        {
            int v = q[qh++];
            id[v] = 2;
            if (qh == n)
                qh = 0;
            for (size_t i = 0; i < g[v].size(); ++i)
            {
                rib &r = g[v][i];
                if (r.f < r.u && d[v] + r.c < d[r.b])
                {
                    d[r.b] = d[v] + r.c;
                    if (id[r.b] == 0)
                    {
                        q[qt++] = r.b;
                        if (qt == n)
                            qt = 0;
                    }
                    else if (id[r.b] == 2)
                    {
                        if (--qh == -1)
                            qh = n - 1;
                        q[qh] = r.b;
                    }
                    id[r.b] = 1;
                    p[r.b] = v;
                    p_rib[r.b] = i;
                }
            }
        }
        if (d[t] == INF)
            break;
        int addflow = k - flow;
        for (int v = t; v != s; v = p[v])
        {
            int pv = p[v];
            size_t pr = p_rib[v];
            addflow = min(addflow, g[pv][pr].u - g[pv][pr].f);
        }
        for (int v = t; v != s; v = p[v])
        {
            int pv = p[v];
            size_t pr = p_rib[v], r = g[pv][pr].back;
            g[pv][pr].f += addflow;
            g[v][r].f -= addflow;
            cost += g[pv][pr].c * addflow;
        }
        flow += addflow;
    }
    cout << flow << '\n';
    for (int i = 0; i < n; i++)
    {
        for (auto &u : g[i])
        {
            if (u.f > 0)
                cout << i + 1 << ' ' << u.b + 1 << ' ' << u.f << '\n';
        }
    }
    cout << endl;

    return 0;
}