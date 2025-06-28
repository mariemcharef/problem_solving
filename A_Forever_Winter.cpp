#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> costs;
vector<bool> checked;

int maxDepth(int node,int depth) {
    vis[node] = true;
    if(adj[node].size()==1){
        return depth+1;
    }
    int ans=0;
    for (int neighbor : adj[node]) {
        if ( !vis[neighbor]) {

            ans=max(ans, maxDepth(neighbor,depth+1));
        }
    }
    return ans;
}
void solve() {
   int n, m, y, x;
    cin >> n >> m;
    int count = 0;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);
    checked= vector<bool>(n);
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
   
    for (int i = 0; i < n; i++) {
        fill(vis.begin(),vis.end(),0);
        
         if(maxDepth(i,0)==3){
             cout<< adj[i].size()<<" "<<adj[adj[i][0]].size()-1<<endl;
             return;
         }  
        
    }
 
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}
