#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;


void solve() {
    ll t,n,c,d,k,x,m;
    cin>>n>>k;
    vector<ll> a(n),pref(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        pref[i+1]=pref[i]+a[i];
    }  
 
    ll mx=0;
    for(ll i=n-1;i>0;i--){
        
        m=100*a[i]/k;
        if(100*a[i]%k >0){
            m++;
        }
        mx=max(mx, (m- pref[i]));

    }
    cout<<mx<<endl;


    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}