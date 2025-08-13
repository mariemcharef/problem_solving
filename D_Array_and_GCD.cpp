#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e7; 
vector<int> max_div(MAX_N + 1, 0);
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

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    auto it = upper_bound(pref_premiers.begin(), pref_premiers.end(), sum);
    int k = it - pref_premiers.begin()-1; // le nombre de premiers dont la somme est <= sum

    if (n <= k) {
        cout << 0 << endl;
        return;
    }
    int ind=0;
    while (n - ind > k) {
        sum -= v[ind];
        ind++;
        if (ind > n) break; 
        it = upper_bound(pref_premiers.begin(), pref_premiers.end(), sum);
        k = it - pref_premiers.begin() - 1;
    }
    cout << ind << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    seive();
    
    for (int i = 2; i <= MAX_N; ++i) {
        if (max_div[i] == i) {
            premiers.push_back(i);
        }
    }

    pref_premiers = vector<ll>(premiers.size() + 1, 0);
    for (size_t i = 1; i < pref_premiers.size(); ++i) {
        pref_premiers[i] = pref_premiers[i - 1] + premiers[i - 1];
    }

    int q;
    cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}
