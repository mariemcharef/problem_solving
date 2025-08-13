#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod = 1e9 +7;
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

void solve() {

    int n;
    cin >> n;
    DSU dsu(n) ;
    vector<int> b(n),c(n),a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++){
        cin >> b[i];
        if(a[i]!=b[i]) dsu.unionn(a[i],b[i]);
    }
    set<int> st,parents;
    for (int i = 0; i < n; i++){
        cin >> c[i];
        if(a[i]==b[i])c[i]=a[i];
        if(c[i]!=0)st.insert(c[i]);
    }
    set<int> ans;

    for(int i=1;i<=n;i++){
     
        if(st.find(i)==st.end()){
            ans.insert(dsu.find(i));
        }
    }
    for(int i=1;i<=n;i++){
     
        if(st.find(i)!=st.end()){
            ans.erase(dsu.find(i));
        }
    }
     
     if(ans.size()==0)cout<<1<<endl;
     else cout<<modpow(2,ans.size(),mod)<<endl;

}


int main()
{
    int tc=1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}

