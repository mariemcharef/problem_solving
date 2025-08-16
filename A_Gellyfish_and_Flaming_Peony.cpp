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
    int t,n,c,d,x,m;

    cin>>n;
    vector<int> a(n),b(n);
    int gcd_nes_lkol;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(i==0)gcd_nes_lkol=b[i];
        gcd_nes_lkol=gcd(gcd_nes_lkol, b[i]);
    } 
    a=b;
    sort(a.begin(),a.end(),greater<>());
    vector<int> steps(a[0]+1,50000);
    for(int i=0;i<a.size();i++){
        steps[a[i]]=0;
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            if(i!=j){
                int x=gcd(a[i],a[j]);
                if(steps[x]==50000)a.push_back(x);
                steps[x]=min(steps[x], steps[a[i]]+steps[a[j]]+1  );
            }
            
        }
    }
    int ans=steps[gcd_nes_lkol];
    if(ans!=0) ans--;
    for(int i=0;i<n;i++){
        if(b[i]!=gcd_nes_lkol)ans++;
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