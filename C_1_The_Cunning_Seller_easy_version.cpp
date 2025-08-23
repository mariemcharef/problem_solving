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
const ll INF = 1e9;
vector<ll> all_numbers_contains_only_9;
bool contains7(ll x) {
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}

long long largestPowerOf3(long long n) {
    long long x = 1;
    int exp = 0;
    while (x * 3 <= n) {
        x *= 3;
        exp++;
    }
    return x; 
}

void solve() {
    ll n;
    cin >> n;
    ll cost = 0;

    while (n > 0) {
        ll p = largestPowerOf3(n);  
        int exp = 0;
        ll temp = p;
        while (temp > 1) { temp /= 3; exp++; } 

        ll a = n / p;
        ll nextPow = p * 3;  
        ll prevPow = (exp > 0 ? p / 3 : 0);

        cost += a * (nextPow + exp * prevPow);
        n -= a * p;
    }

    cout << cost << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    
    cin >> t;
    while (t--) solve();
    return 0;
}