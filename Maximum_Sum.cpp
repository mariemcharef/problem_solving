#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
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

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
struct node{
    int mx;
    int mx2;

    node(int ans0=0,int suml0=0){
        mx=ans0;
        mx2=suml0;
    }
};

class SegTree{
    public:
    int n;
    vector<int> v;
    vector<node> tree;

    SegTree(vector<int> a){
        v=a;
        n=v.size();
        tree.resize(4*n);
        build(0,0,n-1);
    }

    node mrg(node l, node r){
        int mx;
        int mx2;
        vector<int> ab={l.mx,r.mx,r.mx2,l.mx2};
        sort(ab.begin(), ab.end());
        return node(ab[2],ab[3]);
    }

    void build(int id, int ns,int ne){
        if(ns==ne){
            tree[id]=node(v[ns],-1);
            return;
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        build(left,ns,mid);
        build(right,mid+1,ne);
        tree[id]=mrg(tree[left], tree[right]);
    }

    node query(int qs, int qe,int id,int ns, int ne){
        if(qs > ne || qe < ns){ 
            return node(-1e9, -1e9); 
        }
        if(qs <= ns && qe >= ne){
            return tree[id];
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        node l=query(qs,qe,left,ns,mid);
        node r=query(qs,qe,right,mid+1,ne);
        return mrg(l, r);
    }

    void update(int index, int val,int id, int ns,int ne ){
        if(index<ns || index>ne){
            return;
        }
        if(ns==ne){
            tree[id] = node(val, -1);
            return;
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        update(index, val,left,ns,mid);
        update(index,val,right,mid+1,ne);
        tree[id]=mrg(tree[left], tree[right]);
    }
};
 
void solve() {
    ll n,r,q,d,k;
    cin>>n;

    vector<int> a(n), b(n), z(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    SegTree seg=SegTree(a);
    cin>>q;
    while(q--){
        int l, r;
        char t;
        cin>>t>>l>>r;
        if (t=='Q'){
            l--,r--;
            node qr=seg.query(l,r,0,0,n-1);
            cout<<qr.mx+qr.mx2<<endl;
        }else{
            seg.update(l-1,r,0,0,n-1);
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