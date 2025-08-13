#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n), mn(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(i==0){
            mn[i]=v[i];
        }else{
            mn[i]=min(v[i],mn[i-1]);
        }

    }
    for(int i=1;i<n;i++){
        if(v[i] >= 2*mn[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
