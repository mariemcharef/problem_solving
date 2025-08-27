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
    string s;
    cin >> s;
    vector<vector<int>> pref_even(n + 1, vector<int>(26, 0));
    vector<vector<int>> pref_odd(n + 1, vector<int>(26, 0));
    vector<vector<int>> suff_even(n + 1, vector<int>(26, 0));
    vector<vector<int>> suff_odd(n + 1, vector<int>(26, 0));
    if(n==1|| n==3){
        cout<<1<<endl;
        return;
    }
    if(n==2){
        cout<<0<<endl;
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            pref_even[i + 1][j] = pref_even[i][j];
            pref_odd[i + 1][j] = pref_odd[i][j];
        }
        
        if(i % 2 == 0){
            pref_even[i + 1][s[i] - 'a']++;
        } else {
            pref_odd[i + 1][s[i] - 'a']++;
        }
    }
    
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < 26; j++){
            suff_even[i][j] = suff_even[i + 1][j];
            suff_odd[i][j] = suff_odd[i + 1][j];
        }
        
        if(i % 2 == 0){
            suff_even[i][s[i] - 'a']++;
        } else {
            suff_odd[i][s[i] - 'a']++;
        }
    }
    
    if(n % 2 == 1){
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int mx_even = 0, mx_odd = 0;
            
            for(int j = 0; j < 26; j++){
                int even_count = pref_even[i][j] + suff_odd[i + 1][j];
                mx_even = max(mx_even, even_count);

                int odd_count = pref_odd[i][j] + suff_even[i + 1][j];
                mx_odd = max(mx_odd, odd_count);
            }
            
            ans = max(ans, mx_even + mx_odd);
        }
        
        cout <<n-ans<< endl;
        return;
    }
    int mx_even = 0, mx_odd = 0;
    for(int j = 0; j < 26; j++){
        mx_even = max(mx_even, pref_even[n][j]);
        mx_odd = max(mx_odd, pref_odd[n][j]);
    }
    
    cout <<n- mx_even - mx_odd << endl;
}
    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}