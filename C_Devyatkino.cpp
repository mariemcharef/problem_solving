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
const ll INF = 1e9;
vector<ll> all_numbers_contains_only_9;
bool contains7(ll x) {
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}
void solve(){
    ll n;
    cin >> n;
    
    for(int a=0;a<=9;a++){
        string s=to_string(n-a);
        int b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]<='7')b=max(b, s[i]-'0');
        }
        if(a >= 7-b){
            cout<<a<<endl;
            return;
        }
    } 
 

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    
    cin >> t;
    while (t--) solve();
    return 0;
}