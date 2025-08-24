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

    int n,q,x,y,m1,m2;
    cin >> n>>m1>>m2;
    DSU dsu1(n),dsu2(n);
    
    for (int i = 0; i < m1; i++){
        int u,v;
        cin>>u>>v;
        dsu1.unionn(u,v);
    
    }
    for (int i = 0; i < m2; i++){
        int u,v;
        cin>>u>>v;
        dsu2.unionn(u,v);
    
    }
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if((dsu1.find(i)!=dsu1.find(j)) && (dsu2.find(i)!=dsu2.find(j))){
                dsu1.unionn(i,j);
                dsu2.unionn(i,j);
                ans.push_back({i,j});
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto e: ans){
        cout<<e.first<<" "<<e.second<<endl;
    }
    

}


int main()
{
    int tc=1;
    //cin >> tc;
    while (tc--)
    {
        solve();
    }
}

