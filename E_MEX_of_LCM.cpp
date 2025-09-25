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
class SegTree{
    public:
    int n;
    vector<int> v;
    vector<int> tree;

    SegTree(vector<int> a){
        v=a;
        n=v.size();
        tree.resize(4*n);
        build(0,0,n-1);
    }

    int mrg(int l, int r){
        if(l==-1 || r==-1){
            return -1;
        }
        int ans= lcm(l,r);
        if(ans>1e7){
            return -1;
        }
        return ans;
    }

    void build(int id, int ns,int ne){
        if(ns==ne){
            tree[id]=v[ns];
            return;
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        build(left,ns,mid);
        build(right,mid+1,ne);
        tree[id]=mrg(tree[left], tree[right]);
    }

    int query(int qs, int qe,int id,int ns, int ne){
        if(qs<=ns && qe>=ne){
            return tree[id];
        }
        if(qs>ne || qe<qs){
            return -1;
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        int l=query(qs,qe,left,ns,mid);
        int r=query(qs,qe,right,mid+1,ne);
        return mrg(l, r);
    }
    int get(int qs,int qe,int x,int id,int ns,int ne){

        if(qs>ne || qe<ns){
            return -1;
        }
        if (tree[id]!=-1 && x%tree[id]==0){
            return -1;
        }
        if(ns==ne)return ns;
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        int l=get(qs,qe,x,left,ns,mid);
        if(l==-1){
            l=get(qs,qe,x,right,mid+1,ne);
        }
        return l;
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
    ll n,r,d,k;
    cin>>n;

    vector<int> a(n), b(n), z(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    set<int> lcms;
    SegTree seg=SegTree(a);
    for(int i=0; i<n ;i++){
        lcms.insert(a[i]);
        int x=a[i];
        int l=i+1;
        while(x<1e7 && l<n){
            int nx=seg.get(l,n-1,x,0,0,n-1);
            if (nx==-1){
                break;
            }
            x=seg.mrg(x,a[nx]);
            if(x==-1){
                break;
            }
            lcms.insert(x);
            l=nx+1;
        }
    }
    int c=1;
    while (lcms.count(c)){
        c++;
    }
    cout<<c<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}