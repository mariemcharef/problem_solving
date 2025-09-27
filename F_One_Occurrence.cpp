#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair
#define pr pair<int,int>
ll INF = 1e7;

class DSU{
public:
    vector<int> parent,rank;

    DSU(int n){
        parent=vector<int>(n+1);
        rank=vector<int>(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }
    int find(int p){
        if(parent[p]!=p){
            return parent[p]=find(parent[p]);
        }
        return parent[p]=p;
    }
    void unionn(int e1,int e2){
        int pr1=find(e1), pr2=find(e2);
        if(rank[pr1]<rank[pr2]) swap(pr1,pr2);
        parent[pr2]=pr1;
        rank[pr1]+=rank[pr2];
        rank[pr2]=0;
    }
};

long long modpow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

struct node{
    int mn;
    int val;
    node(int mnval=0, int value=10){
        mn=mnval;
        val=value;
    }
};

unordered_map<int,int> pos,pos_last_occ,first_occ;

class SegTree{
    public:
    int n;
    vector<int> v;
    vector<node> tree;
    int mn;
    
    SegTree(vector<int> a){
        v=a;
        n=v.size()-1; 
        tree.resize(4*n);
        build(0,1,n); 
    }

    node mrg(node l, node r){
        if(l.mn<r.mn){
            return l;
        }
        return r;
    }

    void build(int id, int ns,int ne){
        if(ns==ne){
            tree[id]=node(0,v[ns]); 
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
        if(qs<=ns && qe>=ne){
            return tree[id];
        }
        if(qs>ne || qe<ns){ 
            return node(n+1,n+1);
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
            if(pos_last_occ[v[ns]] != ns){
                tree[id]=node(pos_last_occ.count(v[ns]) ? pos_last_occ[v[ns]] : 0, v[ns]);
            }else{
                tree[id]=node(n+1, v[ns]);
            }
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
    ll n,q,m,x,y,k;
    cin >> n ; 
    vector<int> v(n+1); 
    pos.clear();
    pos_last_occ.clear(); 
    first_occ.clear();  
    
    for(int i=1;i<=n;i++){ 
        cin>>v[i];
        if(first_occ.find(v[i]) == first_occ.end()) 
            first_occ[v[i]]=i;
    }
    
    cin>>q;
    vector<vector<int>> queries;
    
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        queries.push_back({r,l,i});
    }
    sort(queries.begin(),queries.end());
    vector<int> ans(q,0);
   
    SegTree seg=SegTree(v);
    int last_r=0;  
    
    for(int i=0;i<q;i++){
        int l=queries[i][1];
        int r=queries[i][0];
        int pos_ans=queries[i][2];
        
        for(int j=last_r+1;j<=r;j++){
            if(first_occ[v[j]] != j){
                seg.update(j,v[j],0,1,n); 
                seg.update(pos_last_occ[v[j]], v[j], 0,1,n);
            }
            pos_last_occ[v[j]]=j;
        }
        last_r=r;
        node result = seg.query(l,r,0,1,n); 
        
        if(result.mn >= l ) 
            ans[pos_ans] = 0;
        else 
            ans[pos_ans] = result.val;
    }
    
    for(int i=0;i<q;i++){
        cout<<ans[i]<<"\n";
    }
}

int main()
{
    int tc=1;
   // cin >> tc;
    while (tc--)
    {
        solve();
    }
}