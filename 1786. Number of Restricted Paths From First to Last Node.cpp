#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int INF = 1e9;
    long long mod = 1e9 + 7;
    vector<vector<pair<int,int>>> graph;
    vector<int> dist;
    vector<int> dp;

    void dijkstra(int n) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist.assign(n+1, INF);
        dist[n] = 0;
        pq.push({0, n});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto [v, w] : graph[u]) {
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    int dfs(int u, int n) {
        if(u == n) return 1;
        if(dp[u] != -1) return dp[u];

        long long ways = 0;
        for(auto [v, w] : graph[u]) {
            if(dist[v] < dist[u]) {
                ways = (ways + dfs(v, n)) % mod;
            }
        }
        return dp[u] = ways;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        graph.assign(n+1, {});
        for(auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        dijkstra(n);
        dp.assign(n+1, -1);
         if(dist[1] == INF) {
       
            return 1;
         }
        
        return dfs(1, n);
    }
};
