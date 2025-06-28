#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<bool> vis;
vector<int> cmp;




void solve() {
    ll n,m,k, x;
    cin >> n>>k;
    m=n-k;
    while(k--){
        cout<<1;
    }
    while(m--){
        cout<<0;
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}
