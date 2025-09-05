#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int INF = 1e9;
    int N = 1e5 + 7;
    vector<int> dist;
    vector<vector<pair<int,int>>> graph;

    void dijkstra(int node, int n, vector<int>& disappear) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist.assign(n, INF);
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
                int newDist=dist[u] + d;
                if((dist[child] > newDist) && disappear[child]>newDist) {
                    dist[child] = newDist;
                    pq.push({dist[child], child});
                }
            }
        }
    }
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        graph.assign(n,{});
        for(auto e:edges){
            graph[e[0]].push_back({e[1],e[2]});
            graph[e[1]].push_back({e[0],e[2]});
        }
        dijkstra(0,n,disappear);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(dist[i]<disappear[i]){
                ans[i]=dist[i];
            }else{
                ans[i]=-1;
            }
        }
        return ans;
    }
};