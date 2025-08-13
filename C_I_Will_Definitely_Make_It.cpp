#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair


void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> v2;
    for(int i=0;i<n;i++){
        if(v[i] >=v[k-1])v2.push_back(v[i]);
    }
    sort(v2.begin(), v2.end());

    int pos=v2[0];
    int chrono=0;
    for(int i=1;i<v2.size();i++){
        chrono = chrono+v2[i]-v2[i-1];
        if (chrono > pos) {
            cout<<"NO"<<endl;
            return;
        }
        
        pos = pos+v2[i]-v2[i-1];
    }
    
cout<<"YES"<<endl;
}
int main() {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}