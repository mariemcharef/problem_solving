#include <bits/stdc++.h>
using namespace std;




bool dfs(int u,int v,map<pair<int,int>,set<int>>& mp, int color,vector<vector<int>>& adj,vector<int>& vis){
    vis[u]=1;
    if(u==v){
        return true;
    }
    bool ok=0;
    for(int neighbor: adj[u]){
        if(!vis[neighbor] && (mp[{u,neighbor}].count(color)>0 ||  mp[{neighbor,u}].count(color)>0)){
            if(dfs(neighbor,v,mp,color,adj,vis)){
                return true;
            }
        }
    }
    return false;



}
void solve() {
    int n,m,q;
    cin >> n>>m;
    vector<vector<int>> adj(n);
    map<pair<int,int>,set<int>> mp;
    for (int i = 0; i < m; i++) {
        int x, y,z;
        cin >> x >> y>>z;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if(x>y)swap(x,y);
        mp[{x,y}].insert(z);
    }
    cin>>q;
    while(q--){
        int ans=0,u,v;
        cin>>u>>v;
        u--,v--;
        for(int i=1;i<=m;i++){//for ech color if we can reach v from u with this color
            vector<int> vis(n);
            if(dfs(u,v,mp,i,adj,vis)){
                ans++;
            }
        }
        cout<<ans<<endl;

    }
    
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin >> t;
    while (t--) solve();
}
