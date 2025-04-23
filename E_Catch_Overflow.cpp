#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair
const ll INF = 1LL << 32;

void solve() {
    ll n;
    cin >> n;
    string x;
    stack<ll> st;
    st.push(1); 
    ll total = 0;
    bool overflow = false;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        
        if (x == "for") {
            ll val;
            cin >> val;
            ll new_mult = st.top() * val;
            if (st.top() != INF && new_mult >= INF) {
                st.push(INF);
            } else {
                st.push(new_mult);
            }
        }
        else if (x == "add") {
            if (st.top() == INF) {
                overflow = true;
            } else {
                total += st.top();
                if (total >= INF) {
                    overflow = true;
                }
            }
        }
        else if (x == "end") {
            st.pop();
        }
    }
    
    if (overflow) {
        cout << "OVERFLOW!!!" << endl;
    } else {
        cout << total << endl;
    }
}

int main() {
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}