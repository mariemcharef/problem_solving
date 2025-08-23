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
bool f(vector<ll>& v,int k,int x){
    int count = 0;
    set<ll> st;
    for(auto &val : v){
        if(val < x) st.insert(val);
        if((int)st.size() == x){
            count++;
            st.clear();
            if(count == k) return true; 
        }
    }
    return false;
}


void solve() {
    int n,m,k;
    cin>>n>>m;
    vector<ll> v(m);
    for(int i=0;i<m;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll ans=0;
    for(int x = 1; x <n; x++){
        auto it  = lower_bound(v.begin(), v.end(), x);
        auto it2 = lower_bound(v.begin(), v.end(), n - x);
        
        ll a = v.end() - it;   
        ll b = v.end() - it2;  
        
        ans += a * b - min(a,b);
        
        
    }

    cout << ans << endl;

   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}