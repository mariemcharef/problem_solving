#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll t,n,x,m;
    cin>>n;
   
    vector<ll> v(n);
    vector<ll> vp,vimp;
    ll sum=0;
    ll ans=-1e9;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i%2==0){
            sum+=v[i];
            vp.push_back(v[i]+i+1);
        }else{
            sum-=v[i];
            vimp.push_back(v[i]+i+1);
        }
    }


    ll add=(n%2==0 && v[n-1]!=v[0])? n-2 : n-1;

    ans=sum+add;
    ll ans2 = -1e18, ans1 = -1e18;
    vector<ll> pref(n+1,1e18);
    
    for(int i=0;i<v.size();i++){
        pref[i+1]=pref[i];
        if(i%2==0){
            pref[i+1]=min(pref[i+1],2*v[i]+i+1);
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(i%2==1){
            ans1=max(ans1, sum+(2*v[i]+i+1)-pref[i]);
        }
    }


    pref.clear();
    pref.resize(n+1,0);
    for(int i=0;i<v.size();i++){
        pref[i+1]=pref[i];
        if(i%2==1){
            pref[i+1]=max(pref[i+1],2*v[i]-i-1);
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(i%2==0){
            ans2=max(ans2, sum-(2*v[i]-i-1)+pref[i]);
        }
    }

    cout<<max({ans, ans1, ans2})<<endl;

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}