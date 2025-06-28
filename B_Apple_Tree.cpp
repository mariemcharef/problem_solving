#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> costs;
vector<bool> checked;

map<ll,ll> mp;
void dfs(int node) {
    vis[node] = true;
    if(adj[node].size()==1 && node!=0){
        mp[node]=1;
    }
  
    for (ll neighbor : adj[node]) {
        if ( !vis[neighbor]) {
            dfs(neighbor);
            mp[node]+=mp[neighbor];
        }
    } 
}
void solve() {
   int n, m,q, y, x;
    cin >> n ;
    int count = 0;
    mp.clear();
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        x--, y--;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    cin>>q;
    dfs(0);
    
    while(q--){
        cin>>x>>y;
        x--;
        y--;
        cout<<mp[x]*mp[y]<<endl;
        // cout<<mp[y]<<endl;
        // cout<<endl;

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
