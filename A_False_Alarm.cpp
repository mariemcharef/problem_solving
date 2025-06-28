#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<bool> vis;
vector<int> costs;
vector<int> cmp;

void dfs(ll node) {
    vis[node] = true;
    cmp.push_back(node);
    for (ll neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor);
        }
    }
}

void solve() {
    ll n, m, y, x;
    cin >> n>>x ;
   
     vector<int> v(n);
   
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    int a=-1,b=-1;
    for(int i=0;i<n;i++){
        if(v[i]==1){
            a=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(v[i]==1){
            b=i;
            break;
        }
    }
    if(a==-1){
        cout<<"YES"<<endl;
        return;
    }
    if(b-a+1 >x){
        cout<<"NO"<<endl;
        return;
    }
     cout<<"YES"<<endl;
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}
