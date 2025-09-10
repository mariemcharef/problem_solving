#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int INF = 1e9;
    int N = 1e5 + 7;
    vector<int> dist;
    vector<vector<vector<int>>> graph;

    void dijkstra(int node, int n) {
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
                int child = childPair[0];
                int start = childPair[1];
                int end = childPair[2];
                if(h <= end){
                    int newDist=max(h , start)+1;
                    if(dist[child] > newDist ) {

                        dist[child] = newDist;
                        pq.push({dist[child], child});
                    }
                }
            }
        }
    }
    int minTime(int n, vector<vector<int>>& edges) {
        graph.assign(n, {});

        for(auto& t : edges) {
            graph[t[0]].push_back({t[1], t[2], t[3]});
        }
        dijkstra(0,n);
        if(dist[n-1]!= INF) return dist[n-1];
        return -1;
    }
};