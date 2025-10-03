#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N=1e5+2;

class SegTree{
    public:
    int n;
    vector<int> v;
    vector<ll> tree;
  vector<ll> lazy, sum;
  vector<bool> upd;

    SegTree(int x){
        n=x;
        tree.resize(4*n);
        lazy.assign(4*n, 0);
        upd.assign(4*n, 0);
        sum.assign(4*n, 0);
    }

    ll mrg(ll l, ll r){
        return l+r;
    }
    void unlazy(int id, int ns, int ne) {
        if (lazy[id] != 0) {
            tree[id] += lazy[id] * (ne - ns + 1);
            if (ns != ne) {
                int l = id*2+1;
                int r = l+1;
                lazy[l] += lazy[id];
                lazy[r] += lazy[id];
                upd[l]=upd[r]=1;
            }
            lazy[id] = 0;
            upd[id]=0; 
        }
    }

    ll get(int qs, int qe,int id,int ns, int ne){
        unlazy(id,ns,ne);
        if(qs > ne || qe < ns){ 
            return 0; 
        }
        if(qs <= ns && qe >= ne){
            return tree[id];
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        ll l=get(qs,qe,left,ns,mid);
        ll r=get(qs,qe,right,mid+1,ne);
        return mrg(l, r);
    }
    void update(int qs,int qe, int val,int id, int ns,int ne ){
        unlazy(id,ns,ne);
        if (qs > ne || qe < ns) return;
        if (qs <= ns && ne <= qe) {
            lazy[id]+=val;
            upd[id]=1;
            unlazy(id,ns,ne);
            return;
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        update(qs,qe, val,left,ns,mid);
        update(qs,qe,val,right,mid+1,ne);
        
        tree[id]=mrg(tree[left], tree[right]);
    }
};

void solve() {
    int n, c;
    scanf("%d %d", &n, &c);
    SegTree seg = SegTree(n);

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
            printf("%lld\n", seg.get(p, q, 0, 0, n - 1));
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