#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<bool> vis;
vector<int> cmp;




void solve() {
    ll n, k, x;
    cin >> n ;
    map<ll,set<ll>,greater<ll>> mp;
    vector<ll> v(n);
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        cin>>x;
        v[i]=x;
        mp[x].insert(i);
    }
    set<ll> st;
    ll ans=0;
    for(auto &e: mp){
        for(ll a:e.second){
            if(!vis[a] && (st.count(a+1)>0 || (a>0 && st.count(a-1)>0) )){
                st.insert(a);
                vis[a]=1;
                int b=a;
                while(b<n-1 && v[b+1]==v[a]){
                    b++;
                    st.insert(b);
                    vis[b]=1;
                }
                b=a;
                while(b>0 && v[b-1]==v[a]){
                    b--;
                    st.insert(b);
                    vis[b]=1;
                }
            }
        }
        for(ll a:e.second){
            
            if(st.count(a+1)==0 && st.count(a)==0 && (a==0 || st.count(a-1)==0 ))ans++;
            st.insert(a);
            vis[a]=1;
            
        }
    }
    cout<<ans<<endl;


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}
