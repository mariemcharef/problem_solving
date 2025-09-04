
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int INF = 6001;
    int N = 1e5 + 7;
    vector<double> dist;
    vector<vector<pair<int,double>>> graph;

    void dijkistra(int node, int n) {
        priority_queue<pair<double, int>> pq;
        dist.assign(n, 0.0);
        dist[node] = 1.0;

        pq.push({1.0, node});

        while(!pq.empty()) {
            auto parent = pq.top();
            pq.pop();

            double h = parent.first;
            int u = parent.second;

            if(h < dist[u]) continue;

            for(auto childPair : graph[u]) {
                int child = childPair.first;
                double d = childPair.second;

                if(dist[child] < dist[u] * d) {
                    dist[child] = dist[u] * d;
                    pq.push({dist[child], child});
                }
            }
        }
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
         graph.assign(n, {});

        for(int i=0;i<edges.size();i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        dijkistra(start_node,n);

        

        return dist[end_node];
    }
};