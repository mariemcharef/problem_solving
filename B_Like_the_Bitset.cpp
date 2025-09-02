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
    ll n,r,b,a,c,d,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            count++;
        }else{
            count=0;
        }
        if(count==k){
            cout<<"NO"<<endl;
            return;
        }
    }
    vector<int>p(n);
    count=n;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            p[i]=count;
            count--;
        }
    }
     for(int i=0;i<n;i++){
        if(s[i]=='1'){
            p[i]=count;
            count--;
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)cout<<p[i]<<" ";
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