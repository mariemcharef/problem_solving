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
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll INF = 1e13;
void solve() {

    ll n,q,a,m,x,y,k;
    cin >> n>>k;
    string s;
    cin>>s;
    vector<ll> v(n);

    int pos=-1;

    for(int i=0;i<n;i++){
        cin>>v[i];
        if(s[i]=='0'){
            pos=i;
            v[i]=-INF;
        }
    }
    ll mx=0, cur=0;
    for(int i=0;i<n;i++){
        cur=max(v[i], cur+v[i]);
        mx=max(mx, cur);
    }

    if(mx>k || (pos==-1 && mx!=k)){
        cout<<"NO"<<endl;
        return;
    }
    ll mxpref=0;
    cur=0;
    if(pos!=-1){

        
        for(int i=pos+1;i<n;i++){
            cur+=v[i];
            mxpref=max(mxpref, cur);
        }
        ll mxsuff=0;
        cur=0;
        for(int i=pos-1;i>=0;i--){
            cur+=v[i];
            mxsuff=max(mxsuff, cur);
        }

        
        v[pos]=k-mxpref-mxsuff;
    }
    cout<<"YES\n";
    for(int j=0;j<n;j++){
        cout<<v[j]<<" ";
    }
    cout<<"\n";

   
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

