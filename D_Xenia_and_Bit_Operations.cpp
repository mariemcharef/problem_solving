#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
    ll val;
    node(ll v = 0) { val = v; }
};

class SegTree {
public:
    int n;
    vector<ll> v;
    vector<node> tree;

    SegTree(vector<ll> &a) {
        v = a;
        n = v.size();
        tree.resize(4 * n);
        bool startWithOr = (int)log2(n) % 2 == 1;//2**3-> or, 2**4 xor
        build(0, 0, n - 1, startWithOr);
    }

    void build(int id, int ns, int ne, bool isOr) {
        if (ns == ne) {
            tree[id] = node(v[ns]);
            return;
        }
        int mid = (ns + ne) / 2;
        int left = id * 2 + 1;
        int right = left + 1;
        build(left, ns, mid, !isOr);//swith lel 3aks
        build(right, mid + 1, ne, !isOr);
        if (isOr)
            tree[id] = node(tree[left].val | tree[right].val);
        else
            tree[id] = node(tree[left].val ^ tree[right].val);
    }

    void update(int index, int val, int id, int ns, int ne, bool isOr) {
        if (index < ns || index > ne) return;
        if (ns == ne) {
            tree[id] = node(val);
            v[index] = val;
            return;
        }
        int mid = (ns + ne) / 2;
        int left = id * 2 + 1;
        int right = left + 1;
        update(index, val, left, ns, mid, !isOr);
        update(index, val, right, mid + 1, ne, !isOr);
        if (isOr)
            tree[id] = node(tree[left].val | tree[right].val);
        else
            tree[id] = node(tree[left].val ^ tree[right].val);
    }
};

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    n = (1 << n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    SegTree seg(a);
    bool startWithOr = ((int)log2(n) % 2 == 1);//2**3-> or, 2**4 xor

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        seg.update(l, r, 0, 0, n - 1, startWithOr);
        cout << seg.tree[0].val << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
