#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int INF = 1e9;
    vector<vector<pair<int,int>>> graph;
    void dijkstra(int node, int n, vector<int>& dist) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist.assign(n, INF);
        dist[node] = 0;
        pq.push({0, node});
        
        while(!pq.empty()) {
            auto [h, u] = pq.top();
            pq.pop();
            if(h > dist[u]) continue;
            
            for(auto [child, d] : graph[u]) {
                if(dist[child] > dist[u] + d) {
                    dist[child] = dist[u] + d;
                    pq.push({dist[child], child});
                }
            }
        }
    }
    
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
         vector<int> dist,dist1; 
        graph.assign(n, {});
        for(auto& edge : edges) {
            int w = (edge[2] != -1) ? edge[2] : INF;
            graph[edge[0]].push_back({edge[1], w});
            graph[edge[1]].push_back({edge[0], w});
        }

        dijkstra(src, n, dist);
        if(dist[dest] < target) return {}; 
        
        vector<vector<int>> newEdges=edges;
        for(auto& e : newEdges){
            if(e[2]==-1){
                e[2]=1;
            }
        }
        graph.assign(n, {});
        for(int j = 0; j < newEdges.size(); j++) {
            int w=newEdges[j][2];
            graph[newEdges[j][0]].push_back({newEdges[j][1], w});
            graph[newEdges[j][1]].push_back({newEdges[j][0], w});
        }
        dijkstra(src, n, dist);
        dijkstra(dest, n, dist1);
        if(dist[dest] > target) return {}; 
        if(dist[dest] == target) {
            return newEdges;
        }
        for(int i = 0; i < edges.size(); i++) {
            if(edges[i][2] == -1) {
                if(dist[edges[i][0]] < dist[edges[i][1]]){
                    if(dist[edges[i][0]]+ dist1[edges[i][1]] <target){
                        newEdges[i][2]=target-(dist[edges[i][0]]+ dist1[edges[i][1]]);
                    }
                }
                else{
                    if(dist1[edges[i][0]]+ dist[edges[i][1]] <target){
                        newEdges[i][2]=target-(dist1[edges[i][0]]+ dist[edges[i][1]]);
                    }
                }
                graph.assign(n, {});
                for(int j = 0; j < newEdges.size(); j++) {
                    int w=newEdges[j][2];
                    graph[newEdges[j][0]].push_back({newEdges[j][1], w});
                    graph[newEdges[j][1]].push_back({newEdges[j][0], w});
                }
                dijkstra(src, n, dist);
                dijkstra(dest, n, dist1);
                if(dist[dest]==target){
                    return newEdges;
                }
            }
        }
        
        return newEdges; 
    }
};