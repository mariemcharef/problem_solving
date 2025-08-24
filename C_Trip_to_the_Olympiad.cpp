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
map<ll,set<ll>> adj;
map<ll,bool> visited;
ll mxN=0;
void dfs(ll node){
    visited[node]=1;
    mxN=max(mxN,node);
    for(ll index:adj[node]){
        if(!visited[node+index]){
            dfs(node+index);
        }
    }

}
int highestBitPosition(unsigned int n) {
    if (n == 0) return -1;
    int pos = 0;
    while (n >>= 1) {
        pos++;
    }
    return pos;
}

void solve(){
    ll l,r, n, x;
    cin>>l>>r;
    ll mx=0;
    
    int r_highest_bit=highestBitPosition(r);
    bool alg1=0;
    bool alg2=0;
    ll ans=0;
    while (r_highest_bit >= 0 && ((r & (1ll << r_highest_bit)) == (l & (1ll << r_highest_bit)))) {
        if(r & (1ll << r_highest_bit))  ans |= (1ll << r_highest_bit);
        r_highest_bit--;
    }
    
    for(int i=r_highest_bit;i>=0;i--){
        if((r & (1ll<<i)) && (l & (1ll<<i)) ){
            alg1=1;
            break;
        }
        if(!(r & 1ll<<i) && !(l & 1ll<<i) ){
            alg2=1;
            break;
        }
    }
    if(alg1){
        ans|=(1ll<<r_highest_bit);
        r_highest_bit--;
        
        for (int i = r_highest_bit; i >= 0; i--) {
            if (!(r & (1ll << i)) && !(l & (1ll << i))) {
                ans |= 1ll << i;
            }
        }
        if(ans>=r)ans=r-1;
        if(ans<=l)ans=l+1;
        cout<<l<<" "<<r<<" "<<ans<<endl;
        return;
    }
    if(alg2){          
        for(int i=r_highest_bit-1;i>=0;i--){
            if(!(r & (1ll<<i)) || !(l & (1ll<<i))){
                ans|=(1ll<<i);
            }
        }
        if(ans>=r)ans=r-1;
        if(ans<=l)ans=l+1;
        cout<<l<<" "<<r<<" "<<ans<<endl;
        return;
    }
    cout<<l<<" "<<r<<" "<<l+1<<endl;  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    
    cin >> t;
    while (t--) solve();
    return 0;
}