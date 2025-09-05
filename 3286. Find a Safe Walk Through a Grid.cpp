#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dx={0,0,1,-1},dy={1,-1,0,0};
    const int INF = 1e9;
    int N = 1e5 + 7;
    vector<vector<int>> dist;

    void dijkstra(int i,int j, int n,int m, vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        dist=vector<vector<int>>(n,vector<int>(m,INF));
        dist[i][j] = grid[i][j];

        pq.push({0, {i,j}});

        while(!pq.empty()) {
            auto parent = pq.top();
            pq.pop();

            int distance = parent.first;
            pair<int,int> u = parent.second;
            int px=u.first;
            int py= u.second;

            if(distance > dist[px][py]) continue;

            for(int i=0;i<4;i++){
                int nx=px+dx[i];
                int ny=py+dy[i];
                pair<int,int> child={nx,ny};
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int newDist=dist[px][py] + grid[nx][ny];
                    if(dist[nx][ny] > newDist){
                        dist[nx][ny]=newDist;
                        pq.push({dist[nx][ny], child});
                    }
                }
            }
            
        }
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(), m=grid[0].size();
        dijkstra(0,0,n,m,grid);
        return dist[n-1][m-1]<health;
        
    }
};