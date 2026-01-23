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

void precompute() {
    for(int j = 0; j < primes.size(); j++){
        int p = primes[j];
        string ps = to_string(p);
        bool ok = true;

        for(char c: ps){
            if(c == '0'){
                ok = false;
                break;
            }
        }
        string temp = ps;
        while (ok && temp.size() > 0) {
            int nps = stoi(temp);
            if (max_div[nps] != nps) {
                ok = false;
                break;
            }
            temp = temp.substr(1);
        }
        if(ok){
            pref[p] = 1;
        }
    }
    for(int i = 1; i <= MAX_N; i++){
        pref[i] += pref[i-1];
    }
}
void solve() {
    int n, x,k;
    int j = 0;
    cin>>n;
    cout<<pref[n]<<"\n";   
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    sieve();
    precompute();
    cin >> t;
    while (t--) solve();
    return 0;
}
