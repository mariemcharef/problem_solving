#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = n;

    for (int i = 0; i < n - 1;) {
        if (v[i] > v[i + 1]) {
            if (i + 2 < n && v[i + 1] > v[i + 2]) {
                ans += 7;
                i += 3;  
            } else {
                ans += 5;
                i += 2;  
            }
        } else {
            i++; 
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}