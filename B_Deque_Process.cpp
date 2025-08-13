#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    string ans = "";
    int i = 0, j = n - 1;
    int turn = 0;
    int count=0;
    while (i <= j && count<n) {
        if (turn % 2 == 0) { 
            if (v[i] > v[j]) {
                ans += 'L';
                count++;
                if(count<n) ans += 'R',count++;
            } else {
                ans += 'R';
                count++;
                if(count<n) ans += 'L',count++;
            }
        } else { 
            if (v[i] < v[j]) {
                ans += 'L';
                count++;
                if(count<n) ans += 'R',count++;
                
            } else {
                ans += 'R';
                count++;
                if(count<n) ans += 'L',count++;
            }
        }
        turn++;
        i++,j--;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
