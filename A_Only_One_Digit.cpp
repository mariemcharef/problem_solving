#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

void solve() {
    
    string s;
    cin >> s;
    char ans='9';
    
    for (int i=0;i<s.length();i++){
        if(s[i]<ans )ans=s[i];
    }
    cout<<ans<<endl;
   
}

int main() {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}