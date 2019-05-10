
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <complex>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#define mp make_pair
#define pb push_back
using namespace std;
const int N = 105;
const int M = 405;
const int INF = 1e9;
struct edge
{
    int to, c, f;
};
edge ed[2 * M];
int dist[N], cured[N];
vector<int> edges[N];
bool bfs(int s, int t)
{
    queue<int> q;
    q.push(s);
    memset(dist, 0, sizeof dist);
    dist[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int e : edges[u])
        {
            int v = ed[e].to;
            if (ed[e].f == ed[e].c)
                continue;
            if (dist[v] == 0)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return (dist[t] != 0);
}
int dfs(int u, int t, int x)
{
    if (x == 0 || u == t)
    {
        return x;
    }
    for (int i = cured[u]; i < edges[u].size(); i++)
    {
        int e = edges[u][i];
        int v = ed[e].to;
        if (dist[v] != dist[u] + 1)
            continue;
        int res = dfs(v, t, min(x, ed[e].c - ed[e].f));
        if (res != 0)
        {
            ed[e].f += res;
            ed[e ^ 1].f -= res;
            return res;
        }
        cured[u]++;
    }
    return 0;
}
int dinits(int s, int t)
{
    int res = 0;

    while (bfs(s, t))
    {
        memset(cured, 0, sizeof cured);
        while (int cur = dfs(s, t, INF))
        {
            res += cur;
        }
        //	cout << res << " ";
    }
    return res;
}
bool used[N];
void dfs2(int v)
{
    if (used[v])
        return;
    used[v] = 1;
    for (int e : edges[v])
    {
        //if (!used[e])
        {
            if (ed[e].f < ed[e].c)
                dfs2(ed[e].to);
        }
    }
}
void dfs3(int p)
{
    return;
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (argc < 3)
    {
        std::cerr << "ERROR: Enter input and ouput file" << std::endl;
        return 1;
    }
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ee;
    for (int i = 0; i < m; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        int e = 2 * i;
        int rev = 2 * i + 1;
        edges[u].push_back(e);
        edges[v].push_back(rev);
        ed[e].to = v;
        ed[e].c += x;
        ed[rev].to = u;
        ed[rev].c += x;
        ee.pb(mp(u, v));
    }
    int res = dinits(1, n);
    dfs2(1);
    //	for (int i = 0; i < n; i++)
    //	{
    //	cout << dist[i] << " ";
    //	}
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        if (used[ee[i].first] != used[ee[i].second])
        {
            ans.pb(i + 1);
        }
    }
    cout << ans.size() << " " << res << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}