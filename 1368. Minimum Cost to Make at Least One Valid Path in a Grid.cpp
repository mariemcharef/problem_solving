#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int INF = 10000;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    vector<pair<int,int>> mp = {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}};
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dist, vector<pair<int,int>>& path) {
        int nx = i + mp[grid[i][j]].first;
        int ny = j + mp[grid[i][j]].second;
        
        if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && dist[nx][ny] > dist[i][j]) {
            dist[nx][ny] = dist[i][j];
            path.push_back({nx, ny});
            dfs(nx, ny, grid, dist, path);
        }
    }
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INF));
        queue<pair<int,int>> starts;
        
        starts.push({0, 0});
        dist[0][0] = 0;
        
        while(!starts.empty()) {
            auto start = starts.front();
            starts.pop();
            
            if(dist[start.first][start.second] < INF) {
                vector<pair<int,int>> path = {start};
                
                dfs(start.first, start.second, grid, dist, path);
                
                for(auto e : path) {
                    for(int i = 0; i < 4; i++) {
                        int nx = e.first + dx[i];
                        int ny = e.second + dy[i];
                        
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            int newDist = dist[e.first][e.second] + 1;
                            if(newDist < dist[nx][ny]) {
                                dist[nx][ny] = newDist;
                                starts.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        
        return dist[n-1][m-1] == INF ? (n + m - 2) : dist[n-1][m-1];
    }
};