#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    const int INF = 6001;
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

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        graph.assign(n+1, {});

        for(auto& t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }

        dijkstra(k, n);

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, dist[i]);
        }

        return ans == INF ? -1 : ans;
    }
};
