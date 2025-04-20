#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    ll t,n,c,d,x,m;
    cin>>n>>c>>d;
    ll mn=1e9;
    set<ll> st;
    vector<ll> v(n*n),ans;

    for(int i=0;i<n*n;i++){
        cin>>v[i];
        mn=min(v[i],mn); 
    }  
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0) {
                ans.push_back(mn);
                continue;
            }
            ans.push_back(mn+c*i+d*j);
        }
    }
    sort(ans.begin(),ans.end());
    sort(v.begin(),v.end());
    if(v==ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}