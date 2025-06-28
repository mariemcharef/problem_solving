#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N=1e5;
vector<vector<ll>> adj;
vector<int> vis;
ll mx = 0;
vector<int> toposort;
vector<int> order;
bool dfs(ll node) {
    if (vis[node] == 1) return true;
    if (vis[node] == 2) return false;
    
    vis[node] = 1;
    for (ll neighbor : adj[node]) {
        if (dfs(neighbor)) {
            return true;
        }
    }
    vis[node] = 2;
    return false;
}

vector<int> pref;

int f(char c,string s){
    pref.assign(s.size(), 0);
    int mx=0;
    for(auto &u :order){
        pref[u] += s[u]==c;
        mx=max(mx,pref[u]);
        for (ll neighbor : adj[u]) {
            pref[neighbor]=max(pref[u],pref[neighbor]);
        }
    }
    return mx;
}


void solve() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    adj.assign(n, {});
    vis.assign(n, 0);
    vector<vector<ll>> dp(n, vector<ll>(26, 0));
    vector<int> indeg(n,0),temp(n,0);
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        indeg[y]++;
    }

    for (ll i = 0; i < n; ++i) {
        if(!vis[i]){
            if(dfs(i)){
                cout<<-1<<endl;
                return;
            }
        }
    }
    queue<int> q;
    for (ll i = 0; i < n; ++i) {
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    //toposort
    while(!q.empty()){
        int u =q.front();
        order.push_back(u);
        q.pop();
        for (ll v : adj[u]) {
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
        }
    }
    int mx=-1;
    for(char c='a';c<='z';c++){
        mx=max(f(c,s),mx);
        
    }
    
    cout<<mx<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
