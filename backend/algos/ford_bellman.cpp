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
using namespace std;

typedef pair<int, long long> ii;

int n, m, s;
vector<ii> g[2000];
vector<long long> d(2000, LLONG_MAX);
bool blacked_eye_peas[2000];

int main(int argc, char **argv)
{
    cin.tie(0);

    if (argc < 3)
    {
        cerr << "ERROR: Enter input and ouput file" << endl;
        return 1;
    }
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);

    cin >> n >> m >> s;
    s--;
    for (int _ = 0; _ < m; _++)
    {
        int b, e;
        long long w;
        cin >> b >> e >> w;
        b--;
        e--;
        g[b].push_back({e, w});
        //        cout << w << endl;
    }
    d[s] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[j] == LLONG_MAX)
                continue;
            for (const ii &to : g[j])
                if (d[to.first] > d[j] + to.second)
                    d[to.first] = d[j] + to.second;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[j] == LLONG_MAX)
                continue;
            for (const ii &to : g[j])
            {
                if (d[j] == LLONG_MIN || d[to.first] > d[j] + to.second)
                {
                    d[to.first] = d[j] = LLONG_MIN;
                    blacked_eye_peas[j] = true;
                    blacked_eye_peas[to.first] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (d[i] == LLONG_MAX)
            cout << "*\n";
        else if (blacked_eye_peas[i])
            cout << "-\n";
        else
        {
            cout << d[i] << '\n';
        }
    }
    return 0;
}