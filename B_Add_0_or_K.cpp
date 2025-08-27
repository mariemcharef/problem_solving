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
    ll n,r,b,k;
    cin >> n>>k;
    vector<ll> ans(n);
    for(int i=0;i<n;i++){
        cin>>ans[i];
        
    }
    if(k%2==1){
        for(int i=0;i<n;i++){
            if(ans[i]%2==1)ans[i]+=k;
        }
    }
    else if(k==2){
        for(int i=0;i<n;i++){
            if(ans[i]%3==0)continue;
            if(ans[i]%3==1)ans[i]+=2;
            else if (ans[i]%3==2)ans[i]+=4;
        }
    }
    else{
        int fuck=k-1;
        for(int i=0;i<n;i++){
            
            ans[i]+=(fuck-(ans[i]%fuck))*k;
            
            

        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
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