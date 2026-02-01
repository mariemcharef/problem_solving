#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e6; 
vector<int> max_div(MAX_N + 1, 0);
vector<ll> primes,pref(MAX_N + 1,0);


void sieve() {
    max_div[0] = max_div[1] = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (max_div[i] == 0) {
            primes.push_back(i);
            max_div[i] = i;
            for (ll j = (ll)i * i; j <= MAX_N; j += i) {
                if (max_div[j] == 0) max_div[j] = i;
            }
        }
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll l = 1, r = *max_element(v.begin(), v.end());
    ll ans = r;

    while (l <= r) {
        ll m = l + (r - l) / 2;
        bool ok = true;

        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ll a = v[i]/m + (v[i]%m > 0);
            pref[i] += 1;
            if (i + a <= n) pref[i + a] -= 1;
        }

        for (int i = 1; i <= n; i++) {
            pref[i] += pref[i - 1];
            if (pref[i] >= k) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            l = m + 1;
        } else {
            ans = m;
            r = m - 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}