#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;
ll mod = 998244353;


ll pow_2(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}


  void solve() {
    ll n,c,d,k;
    cin>>n>>k;

    vector<int> v(n);
    map<int,int> occ, occur; 
    for(int i=0;i<n;i++){
        cin>>v[i];
        occ[v[i]]++;
    }
    for(auto e: occ){
        if(e.second%k != 0){
            cout<<0<<endl;
            return;
        }
    }
    ll ans=0;
    int l=0, r=-1;
    while(l<n ){

        if(r<n-1 && occur[v[r+1]] < (occ[v[r+1]]/k)){
            r++;
            occur[v[r]]++;
            ans+=(r-l+1);
            // cout<<l<<" "<<r<<endl;
        }
        else{
            occur[v[l]]--;
            l++;
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