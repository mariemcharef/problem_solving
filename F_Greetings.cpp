#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;


void solve() {
    ll t,n,c,d,x,m;

    cin>>n;
    vector<ll> a(n),b(n);
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }  
    
    sort(v.begin(),v.end());
    ordered_set st;
    
    ll ans=0;
    for(int i=0;i<n;i++){
        ll it=st.order_of_key(v[i].second);
        ans += st.size() - it;
 
        st.insert(v[i].second);
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