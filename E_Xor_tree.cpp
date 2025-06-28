#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> nbChilds;
vector<int> nodes;
vector<int> init, goal;

vector<pair<int,int>> parent_colors;

void dfs(int node, int parent, int depth, int flip0, int flip1) {

    int current = init[node];
    if (depth % 2 == 0 && flip0 % 2 == 1) current = current==1 ?0 :1;
    if (depth % 2 == 1 && flip1 % 2 == 1) current = current==1 ?0 :1;

    if (current != goal[node]) {
        nodes.push_back(node + 1); 
        if (depth % 2 == 0)
            flip0++;
        else
            flip1++;
    }

    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, depth + 1, flip0, flip1);
        }
    }
}
void solve() {
    ll n, x, y;
    cin >> n;

    adj = vector<vector<ll>>(n);
    init = vector<int>(n);
    goal = vector<int>(n);
    vis = vector<bool>(n, false);
    parent_colors=vector<pair<int,int>>(n);
    nodes.clear();

    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < n; i++) cin >> init[i];
    for (int i = 0; i < n; i++) cin >> goal[i];
    
    dfs(0,-1,0,0,0);

    cout << nodes.size() << "\n";
    for (int node : nodes) {
        cout << node << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
