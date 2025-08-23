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
        if(pr1==pr2)return;
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

    int n,q,x,y,m;
    cin >> n>>m;
    DSU dsu(m);
    set<int> languages;
    int ans=0;
    int all_zeros=true;
    for (int i = 0; i < n; i++){
        int x, y,p;
        cin>>x;
        if (x==0){
            ans++;
            continue;
        }
        if(x>0){
            all_zeros=0;
            cin>>p;
            x--;
            languages.insert(p);
        }
        while(x>0){
            cin>>y;
            dsu.unionn(y, p);
            languages.insert(y);
            x--;
        }
    
    }
   
    set<ll> parents;

    for(int i:languages){
        ll pr=dsu.find(i);
        if(parents.insert(pr).second){
            ans++;
        }
    }
    if(all_zeros==1){
        cout<<ans<<endl;
        return;
    }
    cout<<ans-1<<endl;
    

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

