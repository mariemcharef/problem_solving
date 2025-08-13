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

    ll n,q,x,y;
    cin >> n>>q;
   
    vector<ll> c(n), pref(n+1,0),pref_1(n+1,0);
    for (int i = 0; i < n; i++){
        cin>>c[i];
        pref[i+1]+=pref[i]+c[i];
        pref_1[i+1]+=pref_1[i];
        if(c[i]==1){
            pref_1[i+1]++;
        }
    }
    while(q--) {
        ll l,r;
        cin>>l>>r;
        l--,r--;
        ll gadesh_mn_1=pref_1[r+1]-pref_1[l];
        //cout<<r-l+1 - gadesh_mn_1<<" ";
        ll sum=pref[r+1]-pref[l];
        if(l==r){
            cout<<"NO"<<endl;
        }
        else if(sum >= ((gadesh_mn_1 * 2)+(r-l+1 - gadesh_mn_1))){
            cout<<"YES"<<endl;
            
        }else{
            cout<<"NO"<<endl;
        }
    }
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

