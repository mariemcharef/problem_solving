#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, x;
    cin >> n ;
    string s;
    cin>>s;
    map<char,int> mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    for(int i=1;i<n-1;i++){
        if(mp[s[i]]>1){
            cout<<"Yes"<<endl;
            return;
        }
            
    }
    cout<<"No"<<endl;
    


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}