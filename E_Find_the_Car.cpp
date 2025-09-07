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
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(k + 1), b(k + 1);

    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];

    while (q--) {
        ll x;
        cin >> x;
        
        if (x == 0) {
            cout << 0 << " ";
            continue;
        }
        
        auto it = lower_bound(a.begin() + 1, a.begin() + k + 1, x);
        
        if (*it == x) {
            ll idx = it - a.begin();
            cout << b[idx] << " ";
        }
        else {

            ll idx = it - a.begin();
            ll x1 = a[idx-1], y1 = b[idx-1];
            ll x2 = a[idx], y2 = b[idx];
            ll spead = (y2 - y1) / (x2 - x1);
            ll ans = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
            cout << ans << " ";
        }
    }
    cout << "\n";
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}