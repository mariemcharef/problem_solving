#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e6; 
vector<int> max_div(MAX_N + 1, 0);
vector<ll> primes,pref(MAX_N + 1,0);


void sieve() {
    max_div[0] = max_div[1] = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (max_div[i] == 0) {
            primes.push_back(i);
            max_div[i] = i;
            for (ll j = (ll)i * i; j <= MAX_N; j += i) {
                if (max_div[j] == 0) max_div[j] = i;
            }
        }
    }
}


void solve() {
    int n, x,k;
    cin>>n;
    vector<ll> v(n), pref(n+1), suff(n+2);
    for(int i=0;i<n;i++){
        cin>>v[i];
        pref[i+1]=(pref[i]+(v[i]%2 == 1))%2;
    }
    for(int i=n;i>=0;i--){
        suff[i]=suff[i+1]+(pref[i]==0);
    }
    ll ans=0;
    bool last=0;
    for(int i=1;i<=n;i++){
        if(pref[i]!=pref[i-1])last=!last;
        if(pref[i]==0 && last==0){
            ans+=suff[i];
        }
        else{
            ans+=(n-i)-suff[i];
        }

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
