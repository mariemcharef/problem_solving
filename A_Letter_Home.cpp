#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, s, x;
    cin >> n >> s;
    vector<ll> v(n);

    ll mx = 0;
    ll mn = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }
    if(n==1){
        cout<<abs(v[0]-s)<<endl;
        return;
    }
    if(s>=mx){
        cout<<abs(mn-s)<<endl;
        return;
    }
    if(s<=mn){
        cout<<abs(mx-s)<<endl;
        return;
    }
    ll ans;
    if (abs(mn - s) <= abs(mx - s)) {
        ans = 2 * abs(mn - s) + abs(mx - s);
    } else {
        ans = 2 * abs(mx - s) + abs(mn - s);
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