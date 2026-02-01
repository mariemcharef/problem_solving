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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    set<ll> s;
    vector<ll> freq(n + 2, 0); 
    int p1 = 0, ans = 0;
    ll max_mex=0;
    ll mex=0;
    for(int p2 = 0; p2 < n; p2++) {
        freq[v[p2]]++;
        s.insert(v[p2]);

        while(freq[v[p2]] > 1) {
            freq[v[p1]]--;
            if(freq[v[p1]] == 0) {
                s.erase(v[p1]);
                mex=min(mex,v[p1]);
            }
            p1++;
        }


        while(s.find(mex) != s.end()) mex++;
        
        if(mex>max_mex){
            ans = p2-p1+1;
            max_mex=max(max_mex, mex);
        }
        else if(max_mex==mex && (p2-p1+1) > ans) {
            ans = p2-p1+1;
        }
    }

    cout << ans << endl;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //cin >> t;
    while (t--) solve();
    return 0;
}
