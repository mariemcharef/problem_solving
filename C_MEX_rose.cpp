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
    ll n,k,x;
    cin>>n>>k;
    vector<ll> p(n);

    multiset<int> st;
    for(ll i=0;i<n;i++){
        cin>>x;
        st.insert(x);
    }

    ll ans=0;
    int cur=0;
    while(cur<k){
        if(!st.count(cur))ans++;
        cur++;
    }
    int countk=st.count(k);

    if(ans<countk){
        cout<<countk<<endl;
        return;
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