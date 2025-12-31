#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define vii vector<pair<int, int>>
const int INF = 1e9;
struct path
{
    int u; // nodo
    int d; // distancia acumulada
    bool operator<(const path &other) const { return d > other.d; }
};
vi dijkstra(int s, vector<vii> &G)
{
    vi D(G.size(), INF);
    priority_queue<path> pq;
    pq.push({s, 0});
    D[s] = 0;
    while (!pq.empty())
    {
        auto [u, du] = pq.top();
        pq.pop();
        if (du > D[u])
            continue;
        for (auto e : G[u])
        {
            int v = e.first;
            int dv = du + e.second;
            if (dv < D[v])
            {
                D[v] = dv;
                pq.push({v, dv});
            }
        }
    }
    return D;
}