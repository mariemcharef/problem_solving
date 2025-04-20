#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    ll t,n,x,m;
    cin>>n;
   
    int rep=0;
    map<ll,int> mp;
    for(int i=0;i<n;i++){
        cin>>x;
        if(mp[x]>=1){
            rep=1;
        }
        mp[x]++; 
    }
    if(rep==1){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
     
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}