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
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void solve() {
    ll n,a,b;
    cin >> n>>a>>b;
    vector<ll> v(n);
    set<ll> s;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        
    }
    ll c=a;
    if(a!=b){
        c=min({a,b,gcd(a,b)});
    }
    for(int i=0;i<n;i++){
        s.insert(v[i]%c);
    }
    ll ans=1e18;
    ll m=n;
    while(m--){

        ll temp=*(s.begin()); 
        s.erase(s.begin());
        s.insert(temp+c);
        ans=min(ans,*(s.rbegin())-*(s.begin()));
    }
    cout<<ans<<"\n";

}

    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}