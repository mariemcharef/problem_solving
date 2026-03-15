#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int r, int col, vector<vector<int>>& visited, vector<vector<int>>& heights,vector<vector<int>>& colors,int color) {
        visited[r][col] = 1;

        if(colors[r][col] == 0) colors[r][col] = color;
        else if(colors[r][col] != color) colors[r][col] = 3;

        int n = heights.size();
        int m = heights[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& dir : directions) {
            int newRow = r + dir.first;
            int newCol = col + dir.second;
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !visited[newRow][newCol] && heights[newRow][newCol] >= heights[r][col]) {
                dfs(newRow, newCol, visited, heights, colors, color);
            }
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> colors(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            dfs(i, 0, visited, heights, colors, 1);

        }
        for(int j=0;j<m;j++){
            dfs(0, j, visited, heights, colors, 1);

        }
        visited = vector<vector<int>>(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            dfs(i, m-1, visited, heights, colors, 2);

        }
        for(int j=0;j<m;j++){
            dfs(n-1, j, visited, heights, colors, 2);

        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(colors[i][j] == 3) ans.push_back({i, j});    
            }
        }
        return ans;
    }
    
};

