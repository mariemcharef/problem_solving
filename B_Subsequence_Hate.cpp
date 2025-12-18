#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;

ll mod = 1e9 +7;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void solve() {
    ll k;
    string s;
    cin>>s;
    int n=s.size();
    vector<ll> pref(n+1, 0);
    int ans=n;
    for (int i = 1; i <= n; i++){
        pref[i]=pref[i-1]+ (s[i-1]=='1');
    }
    for(int i=1;i<=n;i++){
        int mn1= min(pref[i], i - pref[i]);
        int mn2=min(pref[n] - pref[i], (n - i) - (pref[n] - pref[i]));
        ans = min(ans, mn1 +mn2);
    }
    int mn = min(pref[n], n-pref[n]);
    ans=min(ans, mn);
    cout << ans<<"\n";
}



int main()
{
    int tc=1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}

