#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<bool> vis;
vector<bool> cats;
int m;
int ans = 0;

void dfs(int node, int c,int parent) {
    if (c > m) {
        return;
    }
    
    bool isleaf = true;
    for (int child : adj[node]) {
        if(child!=parent){
            isleaf = false;
            if (cats[child]) {
                dfs(child, c + 1,node);
            } else {
                dfs(child, 0,node);
            }
        } 
    }
    
    if (isleaf && node != 0) {  
        ans++;
    }
}

void solve() {
    int n, x, y;
    cin >> n >> m;
    cats = vector<bool>(n);
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        cats[i] = b;
    }
    
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
         adj[y].push_back(x);
    }
    
    dfs(0, cats[0] ? 1 : 0,-1);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
