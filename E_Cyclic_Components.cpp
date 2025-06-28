#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<bool> vis;
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
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }

    for (ll i = 0; i < n; i++) {
        cmp.resize(0);
        if (!vis[i] ) {
             dfs(i);
            bool ok=1;
            for(int e:cmp){
                if(adj[e].size()!=2){
                    ok=0;
                    break;
                }
            }
            count+=ok;
        }
    }

    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
