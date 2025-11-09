#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const int MAX_N = 1e7; 
vector<ll> max_div(MAX_N + 1, 0);
vector<ll> premiers;
vector<ll> pref_premiers;

void seive() {
    for (int i = 2; i <= MAX_N; i++) {
        if (max_div[i] == 0) {
            for (int j = i; j <= MAX_N; j += i) {
                max_div[j] = i;
            }
        }
    }
}
bool isPrime(long long x) {
    if(x>1e7)return false;
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (long long i = 5; i * i <= x; i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}
void solve() {
    ll n, k,y, x;
    cin >> n >> y >> x;
    ll l=0,r=2e9;
    ll ans;
    if(x>y){
        swap(x,y);
    }
    while(l+1<r){
        ll mid=l+(r-l)/2;
        ll copies = mid/x + max(0LL, (mid-x)/y);
        ll cp1=ans/x;
        ll cp2=ans/y;
        if(copies>=n){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<r<<"\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    //cin >> t;
    while (t--) solve();

    return 0;
}