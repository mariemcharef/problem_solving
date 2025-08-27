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
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = 0;
    vector<bool> vis(n);
    vector<int> pos_1,pos_0;
    for(int i=0;i<n;i++){
        if(s[i]=='0')pos_0.push_back(i);
        else pos_1.push_back(i);
    }
    int i=pos_0.size()-1;
    int j=pos_1.size()-1;
    while(i>=0){
        if(j>=0 && pos_0[i]<pos_1[j]){
            ans+=pos_0[i]+1;
            i--,j--;
        }
        else{
            ans+=pos_0[i]+1;
            i--;
        }
    }
    int k=0;
    while(k<=j){
        ans+=pos_1[k]+1;
        k++,j--;
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