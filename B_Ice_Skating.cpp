#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod = 1e9 +7;

class DSU{
public:
    vector<vector<pair<int,int>>> parent;
    vector<vector<int>> rank;
    DSU(){
        parent=vector<vector<pair<int,int>>>(1001, vector<pair<int,int>>(1001));
        rank=vector<vector<int>>(1001, vector<int>(1001));
        for(int i=1;i<=1000;i++){
            for(int j=1;j<=1000;j++){
                parent[i][j]={i,j};
                rank[i][j]=1;
            }
        }
    }
    pair<int,int> find(pair<int,int> p){
        if(parent[p.first][p.second]!=p){
            return parent[p.first][p.second]=find(parent[p.first][p.second]);
        }
        return parent[p.first][p.second]=p;
    }
    void unionn(pair<int,int> e1,pair<int,int> e2){
        pair<int,int> pr1=find(e1), pr2=find(e2);
        if(rank[pr1.first][pr1.second] < rank[pr2.first][pr2.second]) swap(pr1,pr2);
        parent[pr2.first][pr2.second]=pr1;
        rank[pr1.first][pr1.second] += rank[pr2.first][pr2.second];
        rank[pr2.first][pr2.second]=0;
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
    cin >> n;
    DSU dsu;

   vector<pair<int ,int>> v;
   
    for (int i = 0; i <n; i++){
        ll x,y;
        cin>>x>>y;

        for(auto p:v){
            if(p.first==x || p.second==y) dsu.unionn(p,{x,y});
        }
        
        v.push_back({x,y});
    
    }  
    set<pair<int,int>> parents;
    ll ans=0;
    for(auto e:v){
        parents.insert(dsu.find({e}));
    }
    
    cout<<parents.size()-1<<endl;

}


int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    while (tc--)
    {
        solve();
    }
}

