#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod =998244353;

ll mod_pow(ll base, ll exp, ll m) {
    ll res = 1;
    base %= m;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return res;
}

void solve() {
    int n;
    ll k;
    cin >> n;

    vector<ll> p(n), q(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    ll mxp = p[0], mxq = q[0];
    int indp = 0, indq = 0;

    for (int i = 0; i < n; i++) {
        if (p[i] > mxp) {
            mxp = p[i];
            indp = i;
        }
        if (q[i] > mxq) {
            mxq = q[i];
            indq = i;
        }
        int a,b;
        
        if(mxp>mxq){
            a=indp,b=i-indp;
        }
        else if(mxp<mxq){
            b=indq,a=i-indq;
        }
        else{
            if(q[i-indp]>p[i-indq]){
                a=indp,b=i-indp;
            }else{
                b=indq,a=i-indq;
            }
        }

        r[i]= (mod_pow(2, p[a], mod) + mod_pow(2, q[b], mod)) % mod;
    }
 
    for(int i=0;i<n;i++)cout<<r[i]<<" ";
    cout<<endl;
    
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}