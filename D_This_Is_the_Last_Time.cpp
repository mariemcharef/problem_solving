#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair


void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<vector<ll>> v(n, vector<ll>(3));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    sort(v.begin(), v.end()); 

    set<ll> st;
    st.insert(k);

    for (int i = 0; i < n; i++) {
        ll l = v[i][0], m = v[i][2], r = v[i][1];

        auto it = st.upper_bound(r); 

        if (it != st.begin()) {
            --it;
            if (*it >= l && *it <= r) {
                st.insert(m);
            }
        }
    }

    cout << *st.rbegin() << endl; 
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}