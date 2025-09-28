#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class SegTree {
public:
    int n;
    vector<ll> v;
    vector<ll> tree;

    SegTree(vector<ll> &a) {
        v = a;
        n = v.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    ll mrg(ll l, ll r) {
        if (l == 0) return r;
        if (r == 0) return l;
        return gcd(l, r);
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
        tree[id] = mrg(tree[left], tree[right]);
    }

    ll query(int qs, int qe, int id, int ns, int ne) {
        if (qs > ne || qe < ns) return 0;
        if (qs <= ns && qe >= ne) return tree[id];
        int mid = (ns + ne) / 2;
        int left = id * 2 + 1;
        int right = left + 1;
        ll l = query(qs, qe, left, ns, mid);
        ll r = query(qs, qe, right, mid + 1, ne);
        return mrg(l, r);
    }

    void update(int index, int val, int id, int ns, int ne) {
        if (index < ns || index > ne) return;
        if (ns == ne) {
            tree[id] = val;
            v[index] = val;
            return;
        }
        int mid = (ns + ne) / 2;
        int left = id * 2 + 1;
        int right = left + 1;
        update(index, val, left, ns, mid);
        update(index, val, right, mid + 1, ne);
        tree[id] = mrg(tree[left], tree[right]);
    }
    int get(int qs, int qe, ll x,int id,int ns, int ne){
        if (qs > ne || qe < ns) return -1;
        if(tree[id]%x==0)return -1;
        if(ns==ne) {
             return ns;
        }
        int mid = (ns + ne) / 2;
        int left = id * 2 + 1;
        int right = left + 1;

        int pos=get(qs, qe,x, left, ns, mid);
        if(pos!=-1){
            return pos;
        }
        return get(qs, qe,x, right, mid+1, ne);
    }
};

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    SegTree seg(a);

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            ll x;
            cin >> l >> r >> x;
            l--, r--;

            if (l == r) {
                cout << "YES\n";
                continue;
            }

            int pos = seg.get(l, r, x, 0, 0, n - 1);

            if (pos == -1) {//melgee chay
                cout << "YES\n"; 
                continue;
            }

            int pos2 = seg.get(pos + 1, r, x, 0, 0, n - 1);

            if (pos2 == -1) {//melge chy
                cout << "YES\n"; 
            } else {//fama bad value okhra
                cout << "NO\n";
            }

        } else {
            int idx, val;
            cin >> idx >> val;
            seg.update(idx - 1, val, 0, 0, n - 1);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}