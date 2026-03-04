#include <bits/stdc++.h>
using namespace std;

typedef long long ll;




struct node{
    vector<ll> sorted;
    vector<ll> pref;
    node(ll val){
        sorted.push_back(val);
        pref.push_back(val);
        
    }
    node(){}
};

class SegTree{
    public:
    int n;
    vector<ll> v;
    vector<node> tree;

    SegTree(vector<ll> a){
        v=a;
        n=v.size();
        tree.resize(4*n);
        build(0,0,n-1);
    }

    node mrg(node l, node r){
        node ans;
        int i=0, j=0;
        while(i<l.sorted.size() && j<r.sorted.size()){
            if(l.sorted[i]<r.sorted[j]){
                ans.sorted.push_back(l.sorted[i]);
                i++;
            }
            else{
                ans.sorted.push_back(r.sorted[j]);
                j++;
            }
        }
        while(i<l.sorted.size()){
            ans.sorted.push_back(l.sorted[i]);
            i++;
        }
        while(j<r.sorted.size()){
            ans.sorted.push_back(r.sorted[j]);
            j++;
        }
        ans.pref.push_back(ans.sorted[0]);
        for(int i=1;i<ans.sorted.size();i++){
            ans.pref.push_back(ans.pref.back()+ans.sorted[i]);
        }
        return ans;
    }

    void build(int id, int ns,int ne){
        if(ns==ne){
            tree[id]=node(v[ns]);
            return;
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        build(left,ns,mid);
        build(right,mid+1,ne);
        tree[id]=mrg(tree[left], tree[right]);
    }

    ll query(int qs, int qe, int k, int id, int ns, int ne) {
        if (qs > ne || qe < ns)
            return 0;

        if (qs <= ns && ne <= qe) {
            int idx = upper_bound(tree[id].sorted.begin(),
                                tree[id].sorted.end(), k)
                    - tree[id].sorted.begin();

            if (idx == 0) return 0;
            return tree[id].pref[idx - 1];
        }

        int mid = (ns + ne) / 2;
        int left = id * 2 + 1;
        int right = left + 1;

        return query(qs, qe, k, left, ns, mid)
            + query(qs, qe, k, right, mid + 1, ne);
    }
   
};



void solve() {
    int n, q;
    cin >> n;
    vector<ll> v(n);

    for (ll &x : v)
        cin >> x;
    
    cin>>q;
    SegTree st(v);
    while(q--){
        int l, r, k;
        cin>>l>>r>>k;
        l--, r--;

        cout << st.query(l, r, k, 0, 0, n - 1) << "\n";       
     }
    

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    //cin >> t;
    while(t--) solve();
}