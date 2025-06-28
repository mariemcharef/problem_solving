#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<bool> vis;
vector<int> cmp;




void solve() {
    ll n, k, x;
    cin >> n >> k;
    vector<ll> v(n);
    vector<ll> u(64, 0), w(64, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    
    for (int j = 0; j < 64; j++) {
        w[j] = 1LL << j;
    }
    
    for (int j = 0; j < 64; j++) {
        for (int i = 0; i < n; i++) {
            if (!(v[i] & (1LL << j))) {
                u[j]++;
            }
        }
    }
    
 
    for (int i = 0; i < n; i++) {
        ans += __builtin_popcountll(v[i]);
    }
    

    for (int j = 0; j < 64; j++) {
        ll cost = u[j] * w[j];
        if (k >= cost) {
            ans += u[j];
            k -= cost;
        } else {
            ans += k / w[j];
            k = 0;
            break;
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
