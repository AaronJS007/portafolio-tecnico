#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define vii vector<pair<int, int>>
const int INF = 1e9;

void process(int v, vector<bool> &taken, vector<vii> &G,
             priority_queue<ii, vii, greater<ii>> &pq)
{
    taken[v] = true;
    for (auto e : G[v])
    {
        if (!taken[e.second])
        {
            pq.push(e);
        }
    }
}

long long prim(int start, int n, vector<vii> &G)
{
    vector<bool> taken(n, false);
    priority_queue<ii, vii, greater<ii>> pq;
    process(start, taken, G, pq);
    long long cost = 0;
    while (!pq.empty())
    {
        ii e = pq.top();
        pq.pop();
        if (!taken[e.second])
        {
            cost += e.first;
            process(e.second, taken, G, pq);
        }
    }
    return cost;
}