#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod = 998244353;
set<pair<int,int>> comp1,comp2;
vector<int> dx={1,-1,0,0},dy={0,0,1,-1};
void dfs(int x,int y,vector<vector<int>>& vis, vector<vector<char>>& grid,int cmp){
    vis[x][y]=1;
    if(cmp==1)comp1.insert({x,y});
    else comp2.insert({x,y});
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == '0') {
            dfs(nx, ny, vis, grid, cmp);
            
        }            
        
    }

}
void solve() {
    comp1.clear();
    comp2.clear();

    int n, r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    vector<vector<int>> vis1(n, vector<int>(n));
    vector<vector<int>> vis2(n, vector<int>(n));

    dfs(r1, c1, vis1, grid, 1);
    dfs(r2, c2, vis2, grid, 2);
 

    ll dist = 25000;
    for (auto a : comp1) {
        for (auto b : comp2) {
            ll dx = a.first - b.first;
            ll dy = a.second - b.second;
            dist = min(dist, dx * dx + dy * dy);
        }
    }
    cout << dist << endl;
}


int main()
{
    int tc=1;
    //cin >> tc;
    while (tc--)
    {
        solve();
    }
}

