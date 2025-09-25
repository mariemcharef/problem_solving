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


ll atMostK(vector<ll>& p, ll n, ll K, ll L, ll R) {
    map<ll,ll> freq;
    ll b = 0;
    ll ans = 0;
    for(ll c = 0; c < n; c++) {
        freq[p[c]]++;
        while(freq.size() > K) {
            freq[p[b]]--;
            if(freq[p[b]] == 0) freq.erase(p[b]);
            b++;
        }

        ll len = c - b + 1;
        if(len >= L) {

            ans += min(len, R) - L + 1;
        }
    }
    return ans;
}

void solve() {
    ll n, k, L, R;
    cin >> n >> k >> L >> R;
    vector<ll> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    ll res = atMostK(p, n, k, L, R) - atMostK(p, n, k - 1, L, R);
    cout << res << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}