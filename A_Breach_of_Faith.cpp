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
    int n,k;
    cin>>n;
    vector<ll> v(2*n),nv(2*n);
    for(int i=0;i<2*n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),greater<>());
    ll a2=v[0]+v[1];
    for(int i=2;i<2*n;i++){
        if(i%2==1)a2+=v[i];
        else a2-=v[i];
    }
    cout<<v[0]<<" "<<a2<<" ";
    for(int i=1;i<2*n;i++){
        cout<<v[i]<<" ";
    }
   
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}