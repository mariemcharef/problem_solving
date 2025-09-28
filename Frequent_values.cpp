#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update> ordered_set;

typedef long long ll;
ll mod = 998244353;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
int INF=1e9;
struct node {
    int left, right;
    int occl, occr;
    int mxOcc;

    node(int l = 0, int r = 0, int ocl = 0, int ocr = 0, int mx = 0) {
        left = l;
        right = r;
        occl = ocl;
        occr = ocr;
        mxOcc = mx;
    }
};

class SegTree {
public:
    int n;
    vector<int> v;
    vector<node> tree;

    SegTree(vector<int> a) {
        v = a;
        n = v.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    node mrg(const node &l, const node &r) {
    if (l.mxOcc == 0) return r; 
    if (r.mxOcc == 0) return l; 

    node ans;
    ans.left = l.left;
    ans.right = r.right;
    ans.mxOcc = max(l.mxOcc, r.mxOcc);

    if (l.right == r.left) {
        ans.mxOcc = max(ans.mxOcc, l.occr + r.occl);
    }

    ans.occl = l.occl;
    if (l.left == r.left) {
        ans.occl += r.occl;
    }

    ans.occr = r.occr;
    if (r.right == l.right) {
        ans.occr += l.occr;
    }

    return ans;
}


    void build(int id, int ns, int ne) {
        if (ns == ne) {
            tree[id] = node(v[ns], v[ns], 1, 1, 1);
            return;
        }
        int mid = (ns + ne) / 2;
        int left = id * 2 + 1;
        int right = left + 1;
        build(left, ns, mid);
        build(right, mid + 1, ne);
        tree[id] = mrg(tree[left], tree[right]);
    }

    node query(int qs, int qe, int id, int ns, int ne) {
        if (qs > ne || qe < ns) {
            return node(); 
        }
        if (qs <= ns && qe >= ne) {
            return tree[id];
        }
        int mid = (ns + ne) / 2;
        int left = id * 2 + 1;
        int right = left + 1;
        node l = query(qs, qe, left, ns, mid);
        node r = query(qs, qe, right, mid + 1, ne);
        return mrg(l, r);
    }

    void update(int index, int val, int id, int ns, int ne) {
        if (index < ns || index > ne) return;
        if (ns == ne) {
            v[ns] = val;
            tree[id] = node(val, val, 1, 1, 1);
            return;
        }
        int mid = (ns + ne) / 2;
        int left = id * 2 + 1;
        int right = left + 1;
        update(index, val, left, ns, mid);
        update(index, val, right, mid + 1, ne);
        tree[id] = mrg(tree[left], tree[right]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n, q;
        cin >> n;
        if (n == 0) break;
        cin >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        SegTree seg(a);

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--; 
            cout << seg.query(l, r, 0, 0, n - 1).mxOcc << "\n";
        }
    }
    return 0;
}

