#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    ll n,a,b, k;
    cin >> n ;
    map <ll,ll> mp1,mp2,mp4,mp3; 
    for (int i = 0; i < n; i++) {
        cin >> a>>b;
        mp1[a]++;
        mp2[b]++;
        mp3[b-a]++;
        mp4[a+b]++;
    }
    ll s=0;
    for(auto x:mp1){
        s+=x.second*(x.second-1);
    }
    for(auto x:mp2){
        s+=x.second*(x.second-1);
    }
    for(auto x:mp4){
        s+=x.second*(x.second-1);
    }
    for(auto x:mp3){
        s+=x.second*(x.second-1);
    }
    cout<<s<<endl;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}