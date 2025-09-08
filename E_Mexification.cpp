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
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void solve() {
    ll n,a,b,k;
    cin >> n>>k;

    vector<ll> v(n);
    map<int, int> occur;
    int mex=0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        occur[v[i]]++;
    }
    for(int i=0;i<=n;i++){
        if(occur[i]==0){
            mex=i;
            break;
        }
    }
    ll ans=0;
    ll count=0;
    for(int i=0;i<n;i++){
        if(occur[v[i]]>1 || v[i]>mex){
            v[i]=mex;
        }
    }
    occur.clear();
    ll sum=0;

    for(int i=0;i<n;i++){
        sum+=v[i];
        occur[v[i]]++;
    }
    for(int i=0;i<=n;i++){
        if(occur[i]==0){
            mex=i;
            break;
        }
    }
    if(k==1){
        cout<<sum<<endl;
        return;
    }
    count=0;
    sum=0;
    for(int i=0;i<n;i++){
        if(v[i]>mex || occur[v[i]]>1){
            count++;
        }else{
            sum+=v[i];
        }
    }
    int ok=0;
    for(int i=mex+1;i<=n;i++){
        if(occur[i]>0){
            ok=1;
            break;
        }
            
    }
    if(ok){
        if(k%2==0){
        cout<<sum+count*mex<<endl;
            return;
        }else{
            cout<<sum+count*(mex+1)<<endl;
            return;
        }

    }
    if(k%2==0){
        cout<<sum+count*mex<<endl;
        return;
    }else{
        cout<<sum+count*(mex-1)<<endl;
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