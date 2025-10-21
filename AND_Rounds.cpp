#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegTree {
public:
    int n;
    vector<ll> v, tree;

    SegTree(const vector<ll>& a) {
        v = a;
        n = v.size();
        tree.resize(4 * n);
        if (n > 0) build(0, 0, n - 1);
    }

    void build(int id, int ns, int ne) {
        if (ns == ne) {
            tree[id] = v[ns];
            return;
        }
        int mid = (ns + ne) / 2;
        int left = id * 2 + 1;
        int right = left + 1;
        build(left, ns, mid);
        build(right, mid + 1, ne);
        tree[id] = tree[left] & tree[right];
    }

    ll get(int qs, int qe, int id, int ns, int ne) {
        if (qs > ne || qe < ns) return LLONG_MAX;
        if (qs <= ns && qe >= ne) return tree[id];
        int mid = (ns + ne) / 2;
        int left = id * 2 + 1;
        int right = left + 1;
        ll l = get(qs, qe, left, ns, mid);
        ll r = get(qs, qe, right, mid + 1, ne);
        return l & r;
    }

    ll query(int l, int r) {
        if (l <= r) return get(l, r, 0, 0, n - 1);
        return get(l, n - 1, 0, 0, n - 1) & get(0, r, 0, 0, n - 1);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    SegTree seg(v);
    vector<ll> ans(n);

    if (k >= n / 2) {
        ll val = seg.tree[0]; 
        for (int i = 0; i < n; i++) ans[i] = val;
    } else {
        for (int i = 0; i < n; i++) {
            int l = (i - k + n) % n;
            int r = (i + k) % n;
            ans[i] = seg.query(l, r);
        }
    }

    for (ll a : ans) cout << a << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) solve();
}
