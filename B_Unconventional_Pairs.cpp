#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> p(n);
    ll count1=0, count0=0;
    for(ll i=0;i<n;i++){
        cin>>p[i];
        
    }
    sort(p.begin(),p.end());
    ll ans=0;
    for(int i=0;i<n;i+=2){
        ans=max(ans,abs(p[i+1]-p[i]));
    }
    cout<<ans<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}