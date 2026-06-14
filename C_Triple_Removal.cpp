#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<int> v(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    vector<int> pref_0(n + 1), pref_1(n + 1), number_of_succ_1(n + 1), number_of_succ_0(n + 1);
    
    for(int i = 1; i <= n; i++){
        pref_0[i] = pref_0[i - 1];
        if(v[i] == 0){
            pref_0[i] += 1;
        }
    }
    
    for(int i = 1; i <= n; i++){
        pref_1[i] = pref_1[i - 1];
        if(v[i] == 1){
            pref_1[i] += 1;
        }
    }

    for(int i = 1; i < n; i += 1){
        number_of_succ_1[i] = number_of_succ_1[i - 1];
        if(v[i] == v[i + 1] && v[i] == 1){
            number_of_succ_1[i] += 1;
        }
    }
    number_of_succ_1[n] = number_of_succ_1[n - 1];

    for(int i = 1; i < n; i += 1){
        number_of_succ_0[i] = number_of_succ_0[i - 1];
        if(v[i] == v[i + 1] && v[i] == 0){
            number_of_succ_0[i] += 1; 
        }
    }
    number_of_succ_0[n] = number_of_succ_0[n - 1]; 
    

    while(q--){
        int l, r;
        cin >> l >> r;

        if( (pref_0[r] - pref_0[l - 1]) % 3 != 0 || (pref_1[r] - pref_1[l - 1]) % 3 != 0 ){
            cout << -1 << "\n"; 
            continue;
        }

        int ans = 0;
        bool b1 = false, b2 = false; 

        if (number_of_succ_0[r] - number_of_succ_0[l - 1] == 1 && r < n && v[r] == 0 && v[r + 1] == 0) { 
            b1 = true;
        }

        if (number_of_succ_1[r] - number_of_succ_1[l - 1] == 1 && r < n && v[r] == 1 && v[r + 1] == 1) {
            b2 = true;
        }
       
        if((number_of_succ_0[r] - number_of_succ_0[l - 1] == 0 || b1) && (number_of_succ_1[r] - number_of_succ_1[l - 1] == 0 || b2)){
            ans++;
        }
        
        ans += (pref_0[r] - pref_0[l - 1]) / 3 + (pref_1[r] - pref_1[l - 1]) / 3;
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}