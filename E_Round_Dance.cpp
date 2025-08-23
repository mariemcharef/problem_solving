#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod = 1e9 +7;

class DSU {
public:
    vector<int> parent, size, nb_edges;

    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        nb_edges.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
            nb_edges[i] = 0;
        }
    }

    int find(int p) {
        if (parent[p] != p) parent[p] = find(parent[p]);
        return parent[p];
    }

    void unionn(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) {
            nb_edges[ra]++; 
            return;
        }
        if (size[ra] < size[rb]) swap(ra, rb);
        parent[rb] = ra;
        size[ra] += size[rb];
        nb_edges[ra] += nb_edges[rb];
        nb_edges[ra]++; 
    }
};


void solve() {
    int n;
    cin >> n;
    DSU dsu(n);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        dsu.unionn(i, x);
    }

    set<int> parents;
    long long mx = 0, mn = 0;
    for (int i = 1; i <= n; i++) {
        int pr = dsu.find(i);
        if (parents.insert(pr).second) {
            mx++;
            if (dsu.nb_edges[pr] == dsu.size[pr] && dsu.size[pr]>2) mn++;
        }
    }

    cout << max(1LL, mn) << " " << mx << "\n";
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}

