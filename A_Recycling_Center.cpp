#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

const int N = int(3e5) + 999;
const int MOD = 998244353;

int p2[N]; 

void solve() {
    int n, c;
    cin >> n >> c;

    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x <= c) {
            v.push_back(x);
        }
    }

    int ans = n - v.size(); 

    sort(v.begin(), v.end(), greater<ll>());

    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (count >= N) break; 
        if (v[i] * (1LL << count) > c) {
            ans++;
        } else {
            count++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

 
    p2[0] = 1;
    for (int i = 1; i < N; ++i)
        p2[i] = (2LL * p2[i - 1]) % MOD;

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
