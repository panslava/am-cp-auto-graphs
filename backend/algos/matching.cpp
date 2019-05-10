
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <vector>

using namespace std;

vector<bool> used(1000);
vector<int> g[1000];
vector<int> match(1000, -1);

bool dfs(int v)
{
    if (used[v])
    {
        return false;
    }
    used[v] = true;
    for (int to : g[v])
    {
        if (match[to] == -1 || dfs(match[to]))
        {
            match[to] = v;
            return true;
        }
    }
    return false;
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
    for (int i = 1; i <= n; ++i)
    {
        int v;
        cin >> v;
        while (v)
        {

            g[i].push_back(n + v);

            cin >> v;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int i = 1; i <= n + m; ++i)
        {
            used[i] = 0;
        }
        dfs(i);
    }
    int cnt = 0;
    for (int i = 1; i <= n + m; ++i)
    {
        if (match[i] != -1)
        {
            ++cnt;
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n + m; ++i)
    {
        if (match[i] != -1)
        {
            cout << match[i] << " " << i - n << "\n";
        }
    }

    cout << endl;
    return 0;
}
