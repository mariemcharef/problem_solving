#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair


void solve() {
    int n;
    ll k;
    cin >> n;

    vector<ll> p(n),s(n),orig(n),pr(n),sr(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    if(s[0]!=p[n-1]){
        cout<<"NO"<<endl;
        return;
    }
    int a = s[0];
    orig[0]=p[0],orig[n-1]=s[n-1];
    for(int i=1;i<n-1;i++){
        ll x = max(p[i],s[i])/a;
        x*=min(p[i],s[i]);
        //  if((p[i]*s[i]) % a != 0 || x==0){
        //      cout<<"NO"<<endl;
        //      return;
        //  }
        orig[i] = x;
    }// regenerate p and s
    pr[0]=orig[0];
    for(int i=1;i<n;i++){
        pr[i]= gcd(pr[i-1],orig[i]);

    }
    sr[n-1]=orig[n-1];
    for(int i=n-2;i>=0;i--){
        sr[i]= gcd(sr[i+1],orig[i]);
    }

    if(p!=pr || s!=sr){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}