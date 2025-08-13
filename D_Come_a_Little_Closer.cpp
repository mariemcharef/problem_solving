#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    
    vector<pair<ll, ll>> p(n), q(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        p[i].first = x;
        q[i].second = x;
        q[i].first = y;
        p[i].second = y;
    }

    if (n == 1 || n == 2) {
        cout << n << endl;
        return;
    }

    sort(q.begin(), q.end()); // sorted by y
    sort(p.begin(), p.end()); // sorted by x

    ll ans = 1e18;

    // ignore point with largest x (p[n-1]) 
    ll x1 = p[0].first;
    ll xn = p[n - 2].first;
    ll y1 = q[0].first;
    if(q[0].first == p[n-1].second && q[0].second == p[n-1].first) y1= q[1].first;

    ll yn = q[n - 1].first;
    if(q[n-1].first == p[n-1].second && q[n-1].second == p[n-1].first) yn= q[n-2].first;

    ll rectangle = (xn - x1 + 1) * (yn - y1 + 1);
    if (rectangle == n-1) rectangle+=min(xn-x1+1,yn-y1+1);
    ans = min(ans, rectangle);

    //ignore point with smallest x (p[0])
    x1 = p[1].first;
    xn = p[n - 1].first;
    y1 = q[0].first;
    if(q[0].first == p[0].second && q[0].second == p[0].first) y1= q[1].first;

    yn = q[n - 1].first;
    if(q[n-1].first == p[0].second && q[n-1].second == p[0].first) yn= q[n-2].first;

    rectangle = (xn - x1 + 1) * (yn - y1 + 1);
    if (rectangle == n-1) rectangle+=min(xn-x1+1,yn-y1+1);
    ans = min(ans, rectangle);

    //ignore point with largest y (q[n-1])
    x1 = p[0].first;
    if(p[0].first == q[n-1].second && p[0].second == q[n-1].first) x1= p[1].first;

    xn = p[n - 1].first;
    if(p[n-1].first == q[n-1].second && p[n-1].second == q[n-1].first) xn= p[n-2].first;

    y1 = q[0].first; 
    yn = q[n - 2].first;
    rectangle = (xn - x1 + 1) * (yn - y1 + 1);
    if (rectangle == n-1) rectangle+=min(xn-x1+1,yn-y1+1);
    ans = min(ans, rectangle);

    //  ignore point with smallest y (q[0])
    x1 = p[0].first;
    if(p[0].first == q[0].second && p[0].second == q[0].first) x1= p[1].first;

    xn = p[n - 1].first;
    if(p[n-1].first == q[0].second && p[n-1].second == q[0].first) xn= p[n-2].first;

    y1 = q[1].first;
    yn = q[n - 1].first;
    rectangle = (xn - x1 + 1) * (yn - y1 + 1);
    if (rectangle == n-1) rectangle+=min(xn-x1+1,yn-y1+1);
    ans = min(ans, rectangle);

    cout << ans << endl;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
