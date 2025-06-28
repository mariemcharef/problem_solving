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
    cin >> n>>m;
    m--;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int i=0;
    while(i<m){
        i=i+v[i];
        if(i==m){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
