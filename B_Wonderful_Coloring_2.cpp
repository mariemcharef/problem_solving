#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<ll, int>> a(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    unordered_map<ll, int> freq;
    vector<pair<int, int>> valid;

    for (int i = 0; i < n; i++) {
        ll val = a[i].first;
        if (freq[val] < k) {
            freq[val]++;
            valid.push_back({i, a[i].second}); 
        }
    }
    int total = valid.size() - (valid.size() % k); 
    vector<int> color(n, 0);
    for (int i = 0; i < total; i++) {
        int orig_idx = valid[i].second;
        color[orig_idx] = (i % k) + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}