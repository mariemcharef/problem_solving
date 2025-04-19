#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    map<ll, int> mb, ma;
    vector<ll> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        mb[x]++;
    }
    
    int ans = 0;
    int r = 0; 
    for (int i = 0; i < m; i++) {
        ma[a[i]]++;
        if (ma[a[i]] <= mb[a[i]]) {
            r++;
        }
    }
    if (r >= k) ans++;
    for (int i = m; i < n; i++) {
      
        if (ma[a[i - m]] <= mb[a[i - m]]) {
            r--;
        }
        ma[a[i - m]]--;
        ma[a[i]]++;
        if (ma[a[i]] <= mb[a[i]]) {
            r++;
        }
        if (r >= k) {
            ans++;
        }
    } 
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}