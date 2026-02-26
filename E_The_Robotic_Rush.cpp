#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    set<ll> a, b;

    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.insert(x);
    }

    for(int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        b.insert(x);
    }

    string s;
    cin >> s;

    map<ll, vector<ll>> lm, rm;

    for(int i : a) {
        auto it = b.upper_bound(i);
        if(it != b.end()) {
            int dist = *it - i;
            rm[dist].push_back(i);
        }

        it = b.lower_bound(i);
        if(it != b.begin()) {
            --it;
            int dist = i - *it;  
            lm[dist].push_back(i);
        }
    }

    set<ll> dead;
    vector<ll> ans(k+1);
    ans[0] = n;

    int c = 0;


    for(int i = 1; i <= k; i++) {
        if(s[i-1] == 'R') c++;
        else c--;

        if(c > 0 ) {
            for(ll r:rm[c])dead.insert(r);
            rm[c].clear();
        } else if(c < 0 ) {
            for(ll l:lm[-c])dead.insert(l);
            lm[-c].clear();
        }
        ans[i] = n-dead.size();

        ans[i] = max(ans[i], 0ll);
    }

    for(int i = 1; i <= k; i++)
        cout << ans[i] << " ";
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
     cin >> t;
    while(t--)
        solve();
}