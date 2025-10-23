#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N=1e5+2;

class SegTree {
public:
    int n;
    vector<int> v;
    vector<ll> tree;
    vector<ll> lazy;

    SegTree(vector<int> &a) {
        v = a;
        n = v.size();
        tree.assign(4 * n,0);
        lazy.assign(4 * n,0);
    }


    ll mrg( ll L,  ll R) {
        return L+R;
    }
       void push(int id, int ns, int ne) {
        if (lazy[id] == 0) return;  
        
        if (ns != ne) {
            int l = id * 2 + 1;
            int r = id * 2 + 2;
            
            int mid = (ns + ne) / 2;
            int llen = mid - ns + 1;
            int rlen = ne - (mid);

            lazy[l] += lazy[id];
            lazy[r] += lazy[id];
            tree[l] += llen*lazy[id];
            tree[r] += rlen*lazy[id];
               
        }
        lazy[id] = 0;
    }

    ll query(int qs, int qe, int id, int ns, int ne) {
        push(id, ns, ne);
        if (qs > ne || qe < ns) return 0;
        if (qs <= ns && ne <= qe) return tree[id];

        int mid = (ns + ne) / 2;
        ll L = query(qs, qe, id * 2 + 1, ns, mid);
        ll R = query(qs, qe, id * 2 + 2, mid + 1, ne);
        return mrg(L, R);
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
        tree[id] = mrg(tree[id * 2 + 1], tree[id * 2 + 2]);
    }
    
    void apply_set(int id, int ns, int ne, int val) {
        int len = ne - ns + 1;
        
        tree[id] += 1ll*len*val;
        
        lazy[id] += (ll)val;
    }

 
    
};

void solve() {
    int n, c;
    scanf("%d %d", &n, &c);
    vector<int>v(n,0);
    SegTree seg = SegTree(v);

    for (int i = 0; i < c; i++) {
        int t, p, q, v;
        scanf("%d", &t);
        if (t == 0) {
            scanf("%d %d %d", &p, &q, &v);
            p--, q--;
            seg.update(p, q, v, 0, 0, n - 1);
        } else {
            scanf("%d %d", &p, &q);
            p--, q--;
            printf("%lld\n", seg.query(p, q, 0, 0, n - 1));
        }
    }
}



int main()
{

   int q;
    scanf("%d", &q);
    while (q--) {
        solve();
    }
    return 0;
}