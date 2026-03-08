#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;
 
ll f(ll a, ll b, ll k) {
    ll d = abs(a - b);
    return min(d, k - d);
}

void solve() {
    ll x,n,d,k;
    cin >> n>>d;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>> v[i];
    }
    ll l=0, r=1e9, ans=-1;
    while(l<=r){
        ll final_h = (l+r)/2;
        ll f_h=final_h;
        for(int i=n-1;i>=0;i--){
            if(v[i]<=f_h){
                f_h+=v[i];
                
            }
        }
        if(f_h<=d){
            ans=final_h;
            l=final_h+1;
        }else{
            r=final_h-1;
        }
    }
    cout<<ans<<"\n";

    
    

   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}