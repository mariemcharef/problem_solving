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

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n), prf(n+1);
    vector<ll> pos_1, pos_3;

    for(int i=0;i<n;i++){
        cin >> a[i];
        prf[i+1] = prf[i] + (a[i]==2);
        if(a[i] == 1) pos_1.push_back(i);
        if(a[i] == 3) pos_3.push_back(i);
    }

    ll ans = 0;
    for(ll i : pos_1){
        for(ll j : pos_3){
            if(i < j){
                ll nb2 = prf[j+1] - prf[i];
                ans = (ans + pow_2(2, nb2) - 1 + mod) % mod;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}