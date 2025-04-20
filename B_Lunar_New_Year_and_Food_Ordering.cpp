#include "bits/stdc++.h"
using namespace std;
using  ll =long long;
#define pb push_back
#define mp make_pair
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), c(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        q.push({c[i], i});
    }

    while (m--) {
        ll t, d;
        cin >> t >> d;
        t--;  

        ll s = 0;
        if (a[t] >= d) {
            a[t] -= d;
            cout << d * c[t] << endl;
        } else {
            s += a[t] * c[t];
            d -= a[t];
            a[t] = 0;

            while (d > 0 && !q.empty()) {
                auto p = q.top();
                int idx=p.second;
                if (a[idx] == 0) {
                    q.pop(); 
                    continue;
                }
                ll take = min(d, a[idx]);
                s += take * c[idx];
                a[idx] -= take;
                d -= take;
                if (a[idx] == 0) q.pop();
            }

            if (d > 0) {
                cout << 0 << endl;
            } else {
                cout << s << endl;
            }
        }
    }
}



        


int main()
{
        
    int tc=1;
    //cin>>tc;
    while(tc--)
    {
        solve();
    }    
        
}