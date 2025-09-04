#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int INF = 100000;
    int N = 1e5 + 7;
    vector<int> dist;
    vector<pair<int,int>> graph[101];

    void dijkistra(int node, int n) {
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
    struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first != b.first) return a.first < b.first; 
        return a.second > b.second; 
    }
    };
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        for(auto e: edges){
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        int ans=-1;
        set<pair<int,int>,cmp> st;
        for(int i=0;i<n;i++){
            dijkistra(i,n);
            int count=0;
            for(int j=0;j<n;j++){
                if(j!=i && dist[j]<=d)count++;
            }
            st.insert({count, i});
        }
        return (*st.begin()).second;
    }
};