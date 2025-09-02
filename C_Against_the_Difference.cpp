#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;
ll mod = 998244353;


ll pow_2(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    vector<int> v(n+1), dp(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    
    vector<vector<int>> positions(n+1);
    
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1];
        
        positions[v[i]].push_back(i);
        
        if(v[i]==1){
            dp[i] = max(dp[i], v[i] + dp[i-1]);
        }
        else if(positions[v[i]].size() >= v[i]) {
            int size=positions[v[i]].size();
            int start_pos = positions[v[i]][size-v[i]] - 1;
            dp[i] = max(dp[i], v[i] + dp[start_pos]);
        }
    }
    
    cout << dp[n] << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}