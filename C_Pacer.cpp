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
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    int last_ind = 0, last_val = 0;

    for (int i = 0; i < n; i++) {
        int ind, val;
        cin >> ind >> val;
        
            if (last_val == val) {
                if(( ind-last_ind-1)>0 && (last_ind%2 != ind%2)){
                    ans += ind - last_ind-1;
                    
                    
                }else{
                    if(last_ind%2 == ind%2){
                        ans+=ind - last_ind;
                     }
                }
            } else {
                if(last_ind%2 != ind%2){
                    ans += ind - last_ind;
              
                }else{
                    if((ind-last_ind-1)>0 ){
                        ans+=ind - last_ind-1;
        
                     }
                }
            }
        

        last_val = val;
        last_ind = ind;
    }
    ans+=m-last_ind;

    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}