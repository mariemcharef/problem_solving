#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod = 1e9 +7;
class DSU{
public:
    vector<int> parent,rank;

    DSU(int n){
        parent=vector<int>(n+1);
        rank=vector<int>(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }
    int find(int p){
        if(parent[p]!=p){
            return parent[p]=find(parent[p]);
        }
        return parent[p]=p;
    }
    void unionn(int e1,int e2){
        int pr1=find(e1), pr2=find(e2);
        if(rank[pr1]<rank[pr2]) swap(pr1,pr2);
        parent[pr2]=pr1;
        rank[pr1]+=rank[pr2];
        rank[pr2]=0;
    }
};
long long modpow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}




int diameter=0;
int dfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
    visited[node] = 1;
    multiset<int> depths = {0, 0};
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            depths.insert(dfs(neighbor, visited, adj));
        }
    }
    auto it = depths.rbegin();
    int largest = *it;
    ++it;
    int second_largest = *it;
    diameter = max(diameter, largest + second_largest);
    return largest + 1;
}

void solve() {
    int n, m;
    cin >> n;
    vector<vector<int>> adj1(n);
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj1[x].push_back(y);
        adj1[y].push_back(x);
    }

    cin >> m;
    vector<vector<int>> adj2(m);
    for (int i = 0; i < m-1; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj2[x].push_back(y);
        adj2[y].push_back(x);
    }

    vector<int> visited;
    int root;

    root = -1;
    for (int node = 0; node < n; node++) {
        if (adj1[node].size() > 1) { root = node; break; }
    }
    if (root == -1) root = 0;
    visited.assign(n, 0);
    diameter = 0;
    dfs(root, visited, adj1);
    int longest_path_a = diameter;

    root = -1;
    for (int node = 0; node < m; node++) {
        if (adj2[node].size() > 1) { root = node; break; }
    }
    if (root == -1) root = 0;
    visited.assign(m, 0);
    diameter = 0;
    dfs(root, visited, adj2);
    int longest_path_b = diameter;

    cout << max({longest_path_a,longest_path_b,(longest_path_a + 1) / 2 + (longest_path_b + 1) / 2 + 1}) << "\n";
}



int main()
{
    int tc=1;
    //cin >> tc;
    while (tc--)
    {
        solve();
    }
}

