#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    ll n, h;
    cin >> h >> n;
    vector<ll> a(n), c(n);
   
    ll s = 0;
   
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    if (s >= h) {
        cout << 1 << endl;
        return;
    }
    ll l = 1, r = 1e18;
    ll ans = 0;
    while (l < r) {
        ll mid =  (r + l) / 2;  
        ll sum = 0;  
        ll f=0;
        for(int i = 0; i < n; i++) {
            f= ((mid-1) / c[i] +1) ;
            if (f >= h) break; 
            sum+=f*a[i];
            if (sum >= h) break;
        }
        if (f >= h || sum>=h) {
            ans = mid;
            r = mid;
        } else {
            l = mid+1;
        }
    }
    cout << l  << endl;  
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q = 1;
     cin >> q;
    while (q--)
    {
        solve();
    }
}