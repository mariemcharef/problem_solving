#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve() {
    
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> b(m);
        for (ll i = 0; i < m; i++) {
            cin >> b[i];
        }
        ll nb_grps = (n + k - 1) / k; 
        bool ok = true;
        for (ll x : b) {
            if (x > nb_grps) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}