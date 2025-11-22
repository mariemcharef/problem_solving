#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<pair<int,int>>> graph;
    vector<vector<int>> edgesWeightes;
      

    void bfs(vector<int>& visited, int t){
        queue<int> q;
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto ne:graph[top]){
                if(!visited[ne.first] && ne.second<=t){
                    q.push(ne.first);
                    visited[ne.first]=1;
                }
            }

        }
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        graph.assign(n, {});
        edgesWeightes.assign(n, {});
        
        for(auto& t : edges) {
            graph[t[1]].push_back({t[0], t[2]});
        }

        int l=1, r=1e6+1;
        while(l<r){
            int mid=(l+r)/2;
            vector<int> visited(n);
            bfs(visited, mid);
            bool ok=1;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                r=mid;
            }
            else{
                l=mid+1;
            }

        }
        if(l==1e6+1){
            return -1;
        }
        return l;
        
        
    }
};