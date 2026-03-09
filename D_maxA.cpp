#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;
 
ll f(ll a, ll b, ll k) {
    ll d = abs(a - b);
    return min(d, k - d);
}

void solve() {
    ll x,n,m,d,k;
    cin>>n>>m>>k;
    vector<vector<ll>> v(n,vector<ll>(m)), pref(n+1,vector<ll>(m+1,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(v[i][j]>k) v[i][j]=1;
            else if (v[i][j]==k)v[i][j]=0;
            else v[i][j]=-1;
            pref[i+1][j+1]=v[i][j];
            pref[i+1][j+1]+=pref[i][j+1];
            pref[i+1][j+1]+=pref[i+1][j];
            pref[i+1][j+1]-=pref[i][j];
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(ll x=1;x<=min(n-i, m-j);x++){
            
                ll sum=pref[i+x][j+x];
                sum-=pref[i][j+x];
                sum-=pref[i+x][j];
                sum+=pref[i][j];
                if(sum<=0)ans=max(ans,x*x);
                
            }
        }
    }
    cout<<ans<<"\n";
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
