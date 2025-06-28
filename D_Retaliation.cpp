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
    ll n;
    cin >> n ;
    vector<ll> v(n+1);
    for(ll i = 1; i <= n; i++){
        cin>>v[i];
    }
    ll y,x;
    if( (n*v[n] - v[1])%(n*n -1) !=0){
        cout<<"NO"<<endl;
        return;
    }
    y=(n*v[n] - v[1])/(n*n -1);
    if( (v[1]-y)%n != 0){
        cout<<"NO"<<endl;
        return;
    }
    x=(v[1]-y)/n;
  
    if(x<0 || y<0){
        cout<<"NO"<<endl;
        return;
    }
   
    for(int i=2;i<=n;i++){
        if(v[i]!=( x*(n-i+1) + y*i)){
        
            cout<<"NO"<<endl;
            return;
        }
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
