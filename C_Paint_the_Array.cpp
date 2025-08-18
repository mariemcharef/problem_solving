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
    ll t,n,c,d,x,m;

    cin>>n;
    vector<ll> b(n);
    ll gcd_all_even_pos, gcd_all_odd_pos;
    for(ll i=0;i<n;i++){
        cin>>b[i];
        if(i==0)gcd_all_even_pos=b[i];
        if(i==1)gcd_all_odd_pos=b[i];
        if(i%2==0){
            gcd_all_even_pos=gcd(gcd_all_even_pos,b[i]);
        }else{
            gcd_all_odd_pos=gcd(gcd_all_odd_pos,b[i]);
        }
    } 
    bool ok=0;
    if(gcd_all_even_pos==gcd_all_odd_pos){
        cout<<0<<endl;
        return;
    }
    
    for(ll i=1;i<n;i+=2){
        if(b[i]%gcd_all_even_pos==0){
            ok=0;
            break;
        }else{
            ok=1;    
        }
    }
    if(ok){
        cout<<gcd_all_even_pos<<endl;
        return;
    }
    for(ll i=0;i<n;i+=2){
        if(b[i]%gcd_all_odd_pos==0){
             ok=0;
            break;
        }else{
            ok=1;    
        }
    }

    if(ok){
        cout<<gcd_all_odd_pos<<endl;
        return;
    }
    cout<<0<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}