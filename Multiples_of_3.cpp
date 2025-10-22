#include <bits/stdc++.h>
using namespace std;

struct node {
    int cnt[3]; 
    node() { cnt[0]=cnt[1]=cnt[2]=0; }
};

class SegTree {
public:
    int n;
    vector<node> tree;
    vector<int> lazy;

    SegTree(int n) : n(n) {
        tree.resize(4*n);
        lazy.assign(4*n, 0);
        build(0, 0, n-1);
    }

    void build(int id, int l, int r) {
        if (l == r) {
            tree[id].cnt[0]=1;
            return;
        }
        int mid = (l + r) / 2;
        build(id*2+1, l, mid);
        build(id*2+2, mid+1, r);
        mrg(id);
    }

    void mrg(int id) {
        for(int i=0;i<3;i++){
            tree[id].cnt[i]=tree[2*id+1].cnt[i]+tree[2*id+2].cnt[i];
        }
    }

    void applyRotate(int id, int times) {
        int r=times%3;
        while(r--){
            int tmp = tree[id].cnt[2];
            tree[id].cnt[2] = tree[id].cnt[1];
            tree[id].cnt[1] = tree[id].cnt[0];
            tree[id].cnt[0] = tmp;
        }        
    }

    void push(int id, int l, int r) {
        if(lazy[id]!=0){
            int md=(l+r)/2;
            applyRotate(2*id+1,lazy[id]%3);
            applyRotate(2*id+2,lazy[id]%3);
            lazy[2*id+1]=(lazy[id] + lazy[2*id+1])%3;
            lazy[2*id+2]=(lazy[id] + lazy[2*id+2])%3;
            lazy[id]=0;
        }
    }

    void update(int id, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            applyRotate(id,1);
            lazy[id]+=1;
            lazy[id]%=3;
            return;
        }
        push(id, l, r);
        int mid = (l + r) / 2;
        update(id*2+1, l, mid, ql, qr);
        update(id*2+2, mid+1, r, ql, qr);
        mrg(id);
    }

    int query(int id, int l, int r, int ql, int qr) {
        if(qr<l || ql>r){
            return 0;
        }
        if(r<=qr && ql<=l){
            return tree[id].cnt[0];
        }
        push(id, l, r);
        int md=(l+r)/2;
        int lft=2*id+1,rgt=lft+1;
        return( query(lft,l,md,ql,qr)+ query(rgt,md+1,r,ql,qr));

    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    SegTree seg(n);

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 0) seg.update(0, 0, n-1, a, b);
        else cout << seg.query(0, 0, n-1, a, b) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
