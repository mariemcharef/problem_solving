#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<bool> vis;
vector<int> cmp;



void dfs(ll node, vector<int>& dp) {
    if(node<0){
        return;
    }
    if (node > 0 && node < dp.size()) {
    if (node - 1 >= 0 && dp[node - 1] > dp[node] + 1) {
        dp[node - 1] = dp[node] + 1;
        dfs(node - 1, dp);
    }
    if (node * 2 < dp.size() && dp[node * 2] > dp[node] + 1) {
        dp[node * 2] = dp[node] + 1;
        dfs(node * 2, dp);
    }
}
    
    
}

void solve() {
    ll n,m, x;
    cin >> n;
   
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    ll s=0;
    for(int i=1;i<n;i++){
        s+=abs(v[i]-v[i-1]);
    }
    
    int mn=1e9;
    mn=min(mn,abs(v[1]-v[0]));
    mn=min(mn,abs(v[n-1]-v[n-2]));
    for(int i=1;i<n-1;i++){
        if(abs(v[i+1]-v[i-1])>=(abs(v[i+1]-v[i])+abs(v[i]-v[i-1])))
            mn=min(mn, abs(v[i+1]-v[i-1])-(abs(v[i+1]-v[i])+abs(v[i]-v[i-1])));
    }
    
    cout<<s-mn<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
