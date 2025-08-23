#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod = 1e9 +7;
vector<ll> cost;
class DSU{
public:
    vector<int> parent,rank;

    DSU(int n){
        parent=vector<int>(n+1);
        rank=vector<int>(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
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
        if(cost[pr1]>cost[pr2]) swap(pr1,pr2);
        parent[pr2]=pr1;
    }
};
ll modpow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

void solve() {

    int n,q,x,y,m;
    cin >> n>>m;
    DSU dsu(n);
    cost.resize(n+1);
    for (int i = 1; i <= n; i++){
        cin>>cost[i];
    }

   
    for (int i = 0; i <m; i++){
        ll u,v;
        cin>>u>>v;
        dsu.unionn(u,v);
    
    }  
    set<ll> parents;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll pr=dsu.find(i);
        if(parents.insert(pr).second){
            ans+=cost[pr];
        }
    }
    
    cout<<ans<<endl;

}


int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    //cin >> tc;
    while (tc--)
    {
        solve();
    }
}

