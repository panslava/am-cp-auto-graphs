#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <random>
#include <iomanip>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define fornb(i, a, b) for (int i = (a); i < (b); ++i)

vector<map<long long, long long>> g;

int32_t main(int32_t argc, char **argv)
{
    ios::sync_with_stdio(false);

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
    forn(i, m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        g[a][b] = w;
        g[b][a] = w;
    }
    set<pair<long long, long long>> djk;
    vector<long long> dist(static_cast<size_t>(n), 1e+10);
    dist[0] = 0;
    vector<bool> used(n);
    djk.insert({0, 0});
    fornb(i, 1, n)
    {
        djk.insert({1e+10, i});
    }
    forn(i, n)
    {
        auto cur = *(djk.begin());
        djk.erase(djk.begin());
        used[cur.second] = true;
        dist[cur.second] = cur.first;
        for (auto u : g[cur.second])
        {
            if (!used[u.first])
            {
                djk.erase({dist[u.first], u.first});
                djk.insert({min(dist[u.first], g[cur.second][u.first] + dist[cur.second]), u.first});
                dist[u.first] = min(dist[u.first], g[cur.second][u.first] + dist[cur.second]);
            }
        }
    }
    for (auto u : dist)
    {
        cout << u << ' ';
    }

    cout << std::endl;
    return 0;
}