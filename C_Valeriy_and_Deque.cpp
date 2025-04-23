#include "bits/stdc++.h"
using namespace std;
using  ll =long long;
#define pb push_back
#define mp make_pair


void solve() {
    ll n, q;
    cin >> n >> q;
    deque<ll> dq;
    vector<ll> ans(n),qur;
    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ans[i];
        mx = max(mx, ans[i]);
        dq.push_back(ans[i]);
    }
    sort(ans.begin(), ans.end());
    
    vector<pair<ll, ll>> initialPairs;
    ll m = 0;
   
    while (dq.front()!=mx) {
        m++;
        ll a = dq.front(); 
        dq.pop_front();
        ll b = dq.front();
        dq.pop_front();
        if (a > b) {
            dq.push_front(a);
            dq.push_back(b);
        } else {
            dq.push_front(b);
            dq.push_back(a);
        }
       initialPairs.push_back({a, b});  
    }
    dq.pop_front();
    while(!dq.empty()){
        qur.push_back(dq.front());
        dq.pop_front();
    }
    while (q--) {
        ll k;
        cin >> k;
        if (k <= initialPairs.size()) {
            cout << initialPairs[k-1].first << " " << initialPairs[k-1].second << endl;
        } else {
          
            cout << mx << " " << qur[(k - m -1) % (n - 1)] << endl;
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