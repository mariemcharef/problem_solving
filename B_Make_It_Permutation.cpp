#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<bool> vis;
vector<int> cmp;




void solve() {
    ll n, k, x;
    cin >> n ;
    cout<<2*(n) -3<<endl;
    cout<<1<<" "<<2<<" "<<n<<endl;
    for(int i=2;i<n;i++){
        
        cout<<i<<" "<<1<<" "<<i<<endl;
        if(i+1 != n)cout<<i<<" "<<i+1<<" "<<n<<endl;
    }
    cout<<n<<" "<<1<<" "<<n<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}
