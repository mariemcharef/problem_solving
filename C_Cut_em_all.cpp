#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> nbChilds;


void dfs(ll node) {
    vis[node]=1;
    nbChilds[node]=1;
    for (ll neighbor : adj[node]) {
        if(!vis[neighbor]){
           dfs(neighbor);
           nbChilds[node]+= nbChilds[neighbor];
        }
    }
}

void solve() {
    ll n, m, y, x;
    cin >> n ;
    adj = vector<vector<ll>>(n);
    vis=vector<bool>(n,false);
    nbChilds=vector<ll>(n);
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        x--, y--;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    if(n%2==1){
        cout<<-1<<endl;
        return;
    }
    int nb_cuts=0;
    dfs(0);
    for(ll e:nbChilds){
        if(e%2==0) nb_cuts++;
    }
    cout<<nb_cuts-1<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
