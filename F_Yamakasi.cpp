#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve() {
    ll s, x, n;
    cin >> n >> s >> x;
    vector<ll> a(n+1), pref(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i]=pref[i-1]+a[i];
    }
    ll ans=0;
    map<ll, int> mp;
    int poin=1;
    for(int r=1;r<=n;r++){
        if(a[r]>x) mp.clear(), poin=r+1;
        else if(a[r]==x){
            int j;
            for(j=poin;j<=r;j++){
                mp[pref[j-1]]++;
            }
            poin=j;
        }
        ans+=mp[pref[r] - s];   
    }    
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}
