#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
    ll sum, mx;
    node(ll s=0, ll m=0){
        sum = s;
        mx = m;
    }
};

class SegTree {
public:
    int n;
    vector<ll> v;
    vector<node> tree;

    SegTree(const vector<ll>& a){
        v = a;
        n = v.size();
        tree.resize(4*n);
        if(n > 0) build(0,0,n-1);
    }

    void build(int id, int ns, int ne){
        if(ns==ne){
            tree[id] = node(v[ns], v[ns]);
            return;
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        build(left,ns,mid);
        build(right,mid+1,ne);
        tree[id] = mrg(tree[left], tree[right]);
    }

    node mrg(const node &l, const node &r){
        return node(l.sum+r.sum, max(l.mx,r.mx));
    }

        void update(int qs,int qe,int id, int ns,int ne){
        if (qs > ne || qe < ns) return;
        if(tree[id].mx==1) return;
        if (ns==ne) {
            ll newv = sqrt(tree[id].sum);
            tree[id] = node(newv, newv);
            return;
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        update(qs,qe,left,ns,mid);
        update(qs,qe,right,mid+1,ne);
        tree[id] = mrg(tree[left], tree[right]);
    }
    node get(int qs, int qe, int id, int ns, int ne){
        if(qs > ne || qe < ns) return node(0ll,0ll);
        if(qs <= ns && qe >= ne) return tree[id];
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        node l=get(qs,qe,left,ns,mid);
        node r=get(qs,qe,right,mid+1,ne);
        return mrg(l,r);
    }


};

void solve(int n) {
    int c;
    vector<ll> v(n);
    for(int i=0;i<n;i++) scanf("%lld", &v[i]);

    SegTree seg(v);

    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        int t, p, q;
        scanf("%d", &t);
        if (t == 0) {
            scanf("%d %d", &p, &q);
            p--, q--;
            seg.update(min(p,q), max(p,q), 0, 0, n - 1);
        } else {
            scanf("%d %d", &p, &q);
            p--, q--;
            printf("%lld\n", seg.get(min(p,q), max(p,q), 0, 0, n - 1).sum);
        }
    }
}

int main(){
      int i=1,q;
    while (~scanf("%d", &q)) {
        printf("Case #%d:\n", i);
        solve(q);
        printf("\n");
        i++;
    }
    return 0;
}
