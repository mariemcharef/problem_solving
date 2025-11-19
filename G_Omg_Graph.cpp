#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e18;

class DSU {
public:
    vector<ll> parent, rnk, mn;

    DSU(ll n) {
        parent.resize(n+1);
        rnk.assign(n+1, 1);
        mn.assign(n+1, INF);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(ll a, ll b, ll w) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;

        if (rnk[pa] < rnk[pb]) swap(pa, pb);

        parent[pb] = pa;
        rnk[pa] += rnk[pb];

        mn[pa] = min({mn[pa], mn[pb], w});
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    ll ans = INF;

    vector<array<ll,3>> edges;

    for (int i = 0; i < m; i++) {
        ll w, x, y;
        cin >> x >> y>>w;
        edges.push_back({w, x, y});
    }

    sort(edges.begin(), edges.end()); 

    DSU dsu(n);

    for (auto &e : edges) {
        ll w = e[0], x = e[1], y = e[2];

        dsu.unite(x, y, w);

        if (dsu.find(1) == dsu.find(n)) {
            int root = dsu.find(1);
            int mnEdge = dsu.mn[root];
            ans = min(ans, w + mnEdge);
        }
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
