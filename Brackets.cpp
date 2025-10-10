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

class SegTree {
public:
    int n;
    vector<int> v;
    vector<node> tree;

    SegTree(const vector<int>& a){
        v = a;
        n = v.size();
        tree.resize(4*n);
        if(n > 0) build(0,0,n-1);
    }

    void build(int id, int ns, int ne){
        if(ns==ne){
            tree[id] = node(v[ns],v[ns]);
            return;
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        build(left,ns,mid);
        build(right,mid+1,ne);
        tree[id] = mrg(tree[left], tree[right]);
    }

    node mrg(node & l, node & r){
       
        return node(l.sum+r.sum, min(l.mn_from_0, l.sum+r.mn_from_0));
    }

    void update(int pos,int id, int ns,int ne){
        if (pos > ne || pos < ns) return;
        if (ns==ne) {
            if(v[ns]==1)v[ns]=-1;
            else v[ns] = 1;

            tree[id] = node(v[ns],v[ns]);
            return;
        }
        int mid=(ns+ne)/2;
        int left=id*2+1;
        int right=left+1;
        update(pos,left,ns,mid);
        update(pos,right,mid+1,ne);
        tree[id] = mrg(tree[left], tree[right]);
    }



};

void solve(int n) {
    int c;
    string s ;
    cin>>s;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        if(s[i]=='(') v[i]=1;
        else v[i]=-1;
    }

    SegTree seg(v);

    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        int t, p, q;
        scanf("%d", &p);
        if(p==0){
            
            if(seg.tree[0].sum==0 &&  seg.tree[0].mn_from_0>=0){
                cout<<"YES"<<endl;
            }
            
            else{
                cout<<"NO"<<endl;
            }
        }else{
            p--;
            seg.update(p,0,0,n-1);
        }

    }
}


    int main(){ 
        for (int test = 1; test <= 10; test++) {
             int n;
              if (!(cin >> n)) break;

              cout << "Test " << test << ":\n"; 
               solve(n);
             } 
               return 0;
             }

