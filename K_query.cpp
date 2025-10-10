#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
    ll sum, mn_from_0;
    node(ll s=0, ll m=0){
        sum = s;
        mn_from_0 = m;
    }
};
const int inf=1e9+1;
class SegTree {
public:
    int n;
    vector<int> v;
    vector<int> tree;

    SegTree(const vector<int>& a){
        v = a;
        n = v.size();
        tree.resize(4*n);
        if(n > 0) build(0,0,n-1);
    }

    void build(int id, int ns, int ne){
        if(ns==ne){
            tree[id] = 0;
            return;
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        build(left,ns,mid);
        build(right,mid+1,ne);
        tree[id] = mrg(tree[left], tree[right]);
    }

    int mrg(int & l, int & r){
       
        return l+r;
    }

    void update(int pos,int val,int id, int ns,int ne){
        if (pos > ne || pos < ns) return;
        if (ns==ne) {
            v[ns]=val;

            tree[id] = 1;
            return;
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        update(pos,val,left,ns,mid);
        update(pos,val,right,mid+1,ne);
        tree[id] = mrg(tree[left], tree[right]);
    }
    int get(int qs, int qe, int id, int ns, int ne){
        if(qs > ne || qe < ns) return 0;
        if(qs <= ns && qe >= ne) return tree[id];
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        int l=get(qs,qe,left,ns,mid);
        int r=get(qs,qe,right,mid+1,ne);
        return mrg(l,r);
    }



};

void solve() {
    int n,x;
    cin>>n;
    int q;
    vector<int> a(n);
    SegTree seg=SegTree(a);
    vector<vector<int>> v;
    for(int i=0;i<n;i++) {
        cin>>x;
        v.push_back({x,-1,i});
    }

    cin>>q;
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin>>l>>r>>k;
        v.push_back({k,l-1,r-1,i});

    }
    vector<int> ans(q);
    sort(v.begin(),v.end(),greater<>());
    for(auto u:v){
        if(u[1]==-1){
            seg.update(u[2],u[0],0,0,n-1);
        }
        else{
            ans[u[3]]=seg.get(u[1],u[2],0,0,n-1);
        }
    }
    for(int a:ans){
        cout<<a<<"\n";
    }

}


int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q = 1;
    // cin >> q;
    while (q--)
    {
        solve();
    } 
return 0;
}

