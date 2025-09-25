#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;
ll mod = 998244353;

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
        return max(l,r);
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
    ll n,r,c,d,k;
    cin>>n;

    vector<int> a(n), b(n), z(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0) z[0]=a[0];
        else z[i]=max(z[i-1], a[i]);
    }
    
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    
    ll sum=0;
    vector<int> vec(2*n+1, -1);
    SegTree seg=SegTree(vec);
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            sum+=(i+1)*(n-i);
        }
        else if (a[i] < b[i] && (i>0 && z[i-1]>=b[i])) {
            int x = b[i];
            int ind = -1;
            ind=seg.query(x,2*n+1,0,0,2*n);
             if(ind != -1) {
                 sum += (ind + 1) * (n - i);
             }
        }
        else if (a[i] > b[i] && (i>0 && z[i-1]>=a[i])) {
            int x = a[i];
            int ind = -1;            
            ind=seg.query(x,2*n+1,0,0,2*n);
            if(ind != -1) {
                sum += (ind + 1) * (n - i);
            }
        }  
        seg.update(a[i],i,0,0,2*n);
    }
    cout<<sum<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}