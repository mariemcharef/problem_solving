#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    const ll INF = 1e18;  
    vector<ll> dist;
    long long mod=1e9+7;
    vector<long long> number_of_ways;  
    vector<vector<pair<int,int>>> graph;

    void dijkstra(int node, int n) {
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq;
        dist.assign(n, INF);
        number_of_ways.assign(n,0);

        number_of_ways[node]=1;
        dist[node] = 0;

        pq.push({0, node});

        while(!pq.empty()) {
            auto parent = pq.top();
            pq.pop();

            ll h = parent.first;
            ll u = parent.second;

            if(h > dist[u]) continue;

            for(auto childPair : graph[u]) {
                int child = childPair.first;
                ll d = childPair.second;

                if(dist[child] > dist[u] + d) {
                    dist[child] = dist[u] + d;
                    number_of_ways[child]=number_of_ways[u] % mod;
                    pq.push({dist[child], child});
                }
                else if(dist[child] == dist[u] + d){
                    number_of_ways[child]=(number_of_ways[child]+number_of_ways[u])%mod;
                }
            }
        }
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        graph.assign(n, {});
        
        for(auto& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        
        dijkstra(0, n);
        
        return number_of_ways[n-1]%mod;  
    }
};