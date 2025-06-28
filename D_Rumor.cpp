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
    cin >> n >> m;
    ll count = 0;
    adj = vector<vector<ll>>(n);
    vis = vector<bool>(n);
    costs=vector<int>(n);
    for(int i = 0; i < n; i++){
        cin>>costs[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    ll ans=0;
    for (ll i = 0; i < n; i++) {
        cmp.resize(0);
        if (!vis[i] ) {
            dfs(i);
           
            int mn=1e9;
            for(int e:cmp){
                mn=min(mn,costs[e]);
            }
            ans+=mn;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
