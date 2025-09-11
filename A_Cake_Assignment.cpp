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

ll factorial(int n) {
    if (n <= 1) return 1;
    ll result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

ll combination_factorial(int n, int k) {
    if (k > n || k < 0) return 0;
    if (k == 0 || k == n) return 1;
    
    ll n_factorial = factorial(n);
    ll k_factorial = factorial(k);
    ll nk_factorial = factorial(n - k);
    
    return n_factorial / (k_factorial * nk_factorial);
}

void solve() {
    ll x, k;
    cin >> k >> x;
    vector<int> path;
    ll a = x;
    ll b = (1ll << (k + 1)) - x;  
    
    if(a == b) {
        cout << 0 << "\n";
        cout << "\n";
        return;
    }
    while(a != b) {
        if(a < b) {
            path.push_back(1);
            b -= a;
            a *= 2;
        } else {
            path.push_back(2);
            a -= b;
            b *= 2;
        }
    } 
    
    cout << path.size() << "\n";
        for(int i=path.size()-1;i>=0;i--) cout << path[i] << " ";
        cout << "\n";
        return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}