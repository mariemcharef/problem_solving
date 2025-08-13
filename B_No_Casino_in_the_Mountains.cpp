#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int ans = 0;
    int c = 0;
    
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            c++;
        } else {
            c = 0; 
        }
        
        if (c == k) {
            i++;
            ans++;
            c = 0; 
        }
    }
    
    cout << ans << endl;
}
int main() {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}