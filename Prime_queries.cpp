#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(long long x) {
    if(x>1e7)return false;
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (long long i = 5; i * i <= x; i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}

class SegTree {
public:
    int n;
    vector<ll> v, tree, lazy;

    SegTree(vector<ll> &a) {
        v = a;
        n = v.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, -1);
        build(0, 0, n - 1);
    }

    void build(int id, int ns, int ne) {
        if (ns == ne) {
            tree[id] = isPrime(v[ns]);
            return;
        }
        int mid = (ns + ne) / 2;
        build(id * 2 + 1, ns, mid);
        build(id * 2 + 2, mid + 1, ne);
        tree[id] = tree[id * 2 + 1] + tree[id * 2 + 2];
    }

    void push(int id, int ns, int ne) {
        if (lazy[id] == -1) return;
        int val = lazy[id];
        if (ns != ne) {
            int mid = (ns + ne) / 2;
            int l = id * 2 + 1;
            int r = id * 2 + 2;
            int llen = mid - ns + 1;
            int rlen = ne - mid;
            lazy[l] = val;
            lazy[r] = val;
            tree[l] = 1ll*llen * val;
            tree[r] = 1ll*rlen * val;
        }
        lazy[id] = -1;
    }

    void apply_set(int id, int ns, int ne, int val) {
        int len = ne - ns + 1;
        tree[id] = len * val;
        lazy[id] = val;
    }

    void update(int qs, int qe, int val, int id, int ns, int ne) {
        push(id, ns, ne);
        if (qe < ns || qs > ne) return;
        if (qs <= ns && ne <= qe) {
            apply_set(id, ns, ne, val);
            return;
        }
        int mid = (ns + ne) / 2;
        update(qs, qe, val, id * 2 + 1, ns, mid);
        update(qs, qe, val, id * 2 + 2, mid + 1, ne);
        tree[id] = tree[id * 2 + 1] + tree[id * 2 + 2];
    }

    ll query(int qs, int qe, int id, int ns, int ne) {
        push(id, ns, ne);
        if (qe < ns || qs > ne) return 0;
        if (qs <= ns && ne <= qe) return tree[id];
        int mid = (ns + ne) / 2;
        return query(qs, qe, id * 2 + 1, ns, mid) +
               query(qs, qe, id * 2 + 2, mid + 1, ne);
    }
};

void solve() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<ll> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    SegTree seg(v);

    for (int i = 0; i < q; i++) {
        char t;
        scanf(" %c", &t);
        if (t == 'A') {
            int l, r;
            scanf("%d %d", &l, &r);
            r--;
            v[r] += l;
            seg.update(r, r, isPrime(v[r]) ? 1 : 0, 0, 0, n - 1);
        } else if (t == 'Q') {
            int l, r;
            scanf("%d %d", &l, &r);
            l--, r--;
            printf("%lld\n", seg.query(l, r, 0, 0, n - 1));
        } else {
            int a, l, r;
            scanf("%lld %d %d", &a, &l, &r);
            l--, r--;
            for (int j = l; j <= r; j++) v[j] = a;
            seg.update(l, r, isPrime(a) ? 1 : 0, 0, 0, n - 1);
        }
    }
}

int main() {
    solve();
    return 0;
}
