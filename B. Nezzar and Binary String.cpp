#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>,
    __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}
struct node {
    int nb_0, nb_1;
    node() : nb_0(0), nb_1(0) {}
    node(int z, int o) : nb_0(z), nb_1(o) {}
};

class SegTree {
public:
    int n;
    vector<int> v;
    vector<node> tree;
    vector<int> lazy;

    SegTree(vector<int> &a) {
        v = a;
        n = v.size();
        tree.resize(4 * n);
        lazy.assign(4 * n, -1);
        build(0, 0, n - 1);
    }
     void build(int id, int ns, int ne) {
        if (ns == ne) {
            tree[id] = node(v[ns] == 0, v[ns] == 1);
            return;
        }
        int mid = (ns + ne) / 2;
        build(id * 2 + 1, ns, mid);
        build(id * 2 + 2, mid + 1, ne);
        tree[id] = mrg(tree[id * 2 + 1], tree[id * 2 + 2]);
    }

    node mrg(const node &L, const node &R) {
        return node(L.nb_0 + R.nb_0, L.nb_1 + R.nb_1);
    }

    node query(int qs, int qe, int id, int ns, int ne) {
        if (qs > ne || qe < ns) return node(0, 0);
        if (qs <= ns && ne <= qe) return tree[id];
        push(id, ns, ne);
        int mid = (ns + ne) / 2;
        node L = query(qs, qe, id * 2 + 1, ns, mid);
        node R = query(qs, qe, id * 2 + 2, mid + 1, ne);
        return mrg(L, R);
    }

    void update(int qs, int qe, int val, int id, int ns, int ne) {
        if (qe < ns || qs > ne) return;
        if (qs <= ns && ne <= qe) {
            apply_set(id, ns, ne, val);
            return;
        }
        push(id, ns, ne);
        int mid = (ns + ne) / 2;
        update(qs, qe, val, id * 2 + 1, ns, mid);
        update(qs, qe, val, id * 2 + 2, mid + 1, ne);
        tree[id] = mrg(tree[id * 2 + 1], tree[id * 2 + 2]);
    }
    
    void apply_set(int id, int ns, int ne, int val) {
        int len = ne - ns + 1;
        if (val == 0) {
            tree[id] = node(len, 0);
        } else {
            tree[id] = node(0, len);
        }
        lazy[id] = val;
    }

    void push(int id, int ns, int ne) {
        if (lazy[id] == -1) return;
        if (ns != ne) {
            int l = id * 2 + 1;
            int r = id * 2 + 2;
            lazy[l] = lazy[id];
            lazy[r] = lazy[id];
            int mid = (ns + ne) / 2;
            int llen = mid - ns + 1;
            int rlen = ne - (mid + 1) + 1;
            if (lazy[id] == 0) {
                tree[l] = node(llen, 0);
                tree[r] = node(rlen, 0);
            } else {
                tree[l] = node(0, llen);
                tree[r] = node(0, rlen);
            }
        }
        lazy[id] = -1;
    }
    
    int get_value(int index) {
        node nd = query(index, index, 0, 0, n - 1);
        return nd.nb_1;
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    string s, f;
    cin >> s >> f;
    vector<int> vf(n, 0);
    for (int i = 0; i < n; ++i) vf[i] = (f[i] == '1');

    SegTree seg(vf);
    vector<pair<int,int>> queries(q);
    for (int i = q - 1; i >= 0; --i) {
        cin >> queries[i].first >> queries[i].second;
    }

    for (int i = 0; i < q; ++i) {
        int l = queries[i].first - 1;
        int r = queries[i].second - 1;
        node nd = seg.query(l, r, 0, 0, n - 1);
        int nb_0 = nd.nb_0, nb_1 = nd.nb_1;
        int len = r - l + 1;
        if (nb_0 * 2 < len) {
            seg.update(l, r, 1, 0, 0, n - 1);
        } else if (nb_1 * 2 < len) {
            seg.update(l, r, 0, 0, 0, n - 1);
        } else {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 0; i < n; ++i) {
        int val = seg.get_value(i); 
        if ((s[i] == '1' && val == 0) || (s[i] == '0' && val == 1)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
