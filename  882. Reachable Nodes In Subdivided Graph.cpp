#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int INF = 1e8;
    int N = 1e5 + 7;
    vector<int> dist;
    vector<vector<pair<int,int>>> graph;

    void dijkstra(int node, int n) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist.assign(n+1, INF);
        dist[node] = 0;

        pq.push({0, node});

        while(!pq.empty()) {
            auto parent = pq.top();
            pq.pop();

            int h = parent.first;
            int u = parent.second;

            if(h > dist[u]) continue;

            for(auto childPair : graph[u]) {
                int child = childPair.first;
                int d = childPair.second;

                if(dist[child] > dist[u] + d) {
                    dist[child] = dist[u] + d;
                    pq.push({dist[child], child});
                }
            }
        }
    }
    int reachableNodes(vector<vector<int>>& edges, int mx, int n) {
        graph.assign(n+1, {});

        for(auto& t : edges) {
            graph[t[0]].push_back({t[1], t[2]+1});
            graph[t[1]].push_back({t[0], t[2]+1});
        }
        int ans=0;
        dijkstra(0,n);
        for(int i=0;i<n;i++){
            if(dist[i]<=mx && dist[i]!=INF)ans++;
        }
        map<pair<int,int> ,int> mp;
        for(auto e:edges){
            int a=e[0];
            int b=e[1];
            int x=dist[a];
            if(x<mx){
                int g=mx-x;
                mp[{a,b}]+=g;
            }
            x=dist[b];
            if(x<mx){
                int g=mx-x;
                mp[{a,b}]+=g;
            }
            ans+=min(e[2], mp[{a,b}]);
        }
    return ans;
    }
};