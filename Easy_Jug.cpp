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
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void solve() {
    int n, y,z,x,k;
    int j = 0;
    cin>>x>>y>>z;
    if(x>y) swap(x,y);
    if(z>y){
        cout<<"NO\n";
        return; 
    }
    if(z%gcd(x,y) ==0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    cin >> t;
    while (t--) solve();
    return 0;
}
