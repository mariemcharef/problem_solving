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
void solve() {

    ll n,q,a,b,y;
    cin >>n;
    vector<int> v(n), pref(n+1);
    set<int> st;
    for(int i=0;i<n;i++){
        cin>>v[i];
        st.insert(v[i]);

    }
    int greatest=-1, smallest=-1;
    for(int i=1;i<=n;i++){
        if(!st.count(i)){
            smallest=i;
            break;
        }
    }
    for(int i=n;i>=1;i--){
        if(!st.count(i)){
            greatest=i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(v[i]==0){
            v[i]=greatest;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(v[i]==0){
            v[i]=smallest;
            break;
        }
    }
    int x=smallest+1;
    for(int i=0;i<n;i++){
        if(v[i]==0){
            v[i]=x;
            x++;
        }
    }
    vector<int> sorted_v=v;
    sort(sorted_v.begin(), sorted_v.end());
    int l=-1;
    for(int i=0;i<n;i++){
        if(sorted_v[i]!=v[i]){
            l=i;
            break;
        }
    }
    int r=-1;
    for(int i=n-1;i>=0;i--){
        if(sorted_v[i]!=v[i]){
            r=i;
            break;
        }
    }
    if(l==-1){
        cout<<0<<endl;
        return;
    }
   cout<<r-l+1<<endl;
 

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

 