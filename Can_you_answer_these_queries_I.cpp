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
    int ans;
    int suml,sumr;
    int sum;
    node(int ans0=0,int suml0=0,int sumr0=0,int sum0=0){
        ans=ans0;
        suml=suml0;
        sumr=sumr0;
        sum=sum0;
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
        int ans=max({l.ans, r.ans, l.sumr+r.suml});
        int sum=l.sum+r.sum;
        int suml=max(l.suml,l.sum+r.suml);
        int sumr=max(r.sumr,r.sum+l.sumr);
        return node(ans, suml, sumr, sum);
    }

    void build(int id, int ns,int ne){
        if(ns==ne){
            tree[id]=node(v[ns],v[ns],v[ns],v[ns]);
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
            return node(-1e9, -1e9, -1e9, 0); 
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
            tree[id]=val;
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
        cin>>l>>r;
        l--,r--;
        cout<<seg.query(l,r,0,0,n-1).ans<<endl;
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