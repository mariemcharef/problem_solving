#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(n==2){
        cout<<0<<endl;
        return;
    }
    vector<bool> isLeaf(n, false);
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            isLeaf[i] = true;
        }
    }

    vector<int> leafCount(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (isLeaf[v]) {
                leafCount[u]++;
            }
        }
    }

    int bestNode = 0;
    int maxLeaves = leafCount[0];
    for (int i = 1; i < n; i++) {
        if (leafCount[i] > maxLeaves) {
            maxLeaves = leafCount[i];
            bestNode = i;
        }
    }
    int ans=0;
    int root = bestNode;
    for(int i=0;i<n;i++){
        if(adj[i].size()==1 && adj[i][0]!=root)ans++;
    }
    cout << ans << "\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
