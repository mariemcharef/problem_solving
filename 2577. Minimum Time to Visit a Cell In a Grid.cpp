#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dx={0,0,1,-1},dy={1,-1,0,0};
    const long long INF = 1e18;
    int N = 1e5 + 7;
    int lstValue;
    vector<vector<long long>> dist;

    void dijkstra(int i,int j, int n,int m, vector<vector<int>>& grid) {
        priority_queue<pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<>> pq;
        dist=vector<vector<long long>>(n,vector<long long>(m,INF));
        dist[i][j] = 0;
        pq.push({0, {i,j}});
        while(!pq.empty()) {
            auto parent = pq.top();
            pq.pop();

            long long distance = parent.first;
            pair<int,int> u = parent.second;
            int px=u.first;
            int py= u.second;
            if(distance > dist[px][py]) continue;
            for(int i=0;i<4;i++){
                int nx=px+dx[i];
                int ny=py+dy[i];
                pair<int,int> child={nx,ny};
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    long long newDist= dist[px][py] +1;
                    if (newDist < grid[nx][ny]) {
                        long long wait= 1ll * grid[nx][ny]-newDist;
                        if(wait % 2 == 1){
                            newDist= grid[nx][ny]+1;
                        }else{
                            newDist= grid[nx][ny];
                        }
                    }
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        pq.push({newDist, {nx, ny}});
                    }
                }
            }
            
        }
    }
    int minimumTime(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        if(moveTime[0][1]>1 && moveTime[1][0]>1)return -1;
        dijkstra(0,0,n,m,moveTime);
        long long ans= dist[n-1][m-1];
        if(ans<moveTime[n-1][m-1])ans+=2;
       
        return ans;
    }
};