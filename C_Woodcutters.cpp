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
    int n;
    cin>>n;
    vector<int> p(n),h(n);

    for(int i=0;i<n;i++){
        cin>>p[i];
        cin>>h[i];
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    int ans=2;
    bool occ=0;
    for(int i=1;i<n-1;i++){
        if((!occ && p[i]-p[i-1] > h[i]) || (occ && (p[i]-p[i-1]-h[i-1] ) > h[i])){
            ans++;
            occ=0;
            continue;
        }
        if(p[i+1]-p[i]>h[i]){
            ans++;
            occ=1;
            continue;
        }
        occ=0;
    }
    cout<<ans<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     //cin >> t;
    while (t--) solve();
    return 0;
}