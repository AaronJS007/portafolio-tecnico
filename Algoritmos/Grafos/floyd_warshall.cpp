#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define vii vector<pair<int, int>>
const int INF = 1e9;

const int MAX=100;

struct Floyd
{
    int n;
    long long g[MAX][MAX];
    void init(int n_)
    {
        n = n_;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                g[i][j] = i == j ? 0 : INF;
            }
        }
    }
    void add_edge(int u, int v, long long w)
    {
        g[u][v] = min(g[u][v], w);
    }
    void run()
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
                }
            }
        }
    }
    bool in_neg_cycle(int u) { return g[u][u] < 0; }
};