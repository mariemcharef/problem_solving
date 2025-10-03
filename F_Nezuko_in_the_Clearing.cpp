
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

ll lastPowerOf2(ll n) {
    if (n < 1) return 0;  
    ll p = 1;
    while (p <= n) {
        p <<= 1;
    }
    return p >> 1;
}
bool canReach(ll x,ll d,ll h){
    ll pauses=x-d;
    ll grps=(pauses+1);
    
    ll distance=d/grps;
    ll rest=d%grps;

    ll grps_d=grps-rest;
    ll sm=grps_d*1ll*(distance*(distance+1)/2)+rest*1ll*((distance+1)*(distance+2)/2);

    ll healtch=h+pauses;

    if(healtch-sm>0){
        return true;
    }
    return false;

}

void solve() {
    ll n,h,d, k;
    cin >> h >> d;

    ll l=d,r=2*d,md;
    while(l<r){
        md=l+(r-l)/2;
        if(canReach(md,d,h)){
            r=md;
        }else{
            l=md+1;
        }

    }


    cout << l << "\n";  
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}