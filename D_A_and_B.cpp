#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll ans1 = LLONG_MAX, ans2 = LLONG_MAX;

    int fst = -1, lst = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            fst = i;
            break;
        }
    }
    if (fst != -1) {
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'a') {
                lst = i;
                break;
            }
        }
        int counta = 0;
        vector<int> pref(n + 1, 0);
        for (int i = fst; i <= lst; i++) {
            pref[i] = (i == fst ? 0 : pref[i - 1]);
            if (s[i] == 'a') pref[i]++, counta++;
        }
        ans1 = 0;
        for (int i = fst; i <= lst; i++) {
            if (s[i] != 'a') {
                ans1 += min(pref[i], counta - pref[i]);
            }
        }
    }

    fst = -1, lst = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            fst = i;
            break;
        }
    }
    if (fst != -1) {
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'b') {
                lst = i;
                break;
            }
        }
        int countb = 0;
        vector<int> pref(n + 1, 0);
        for (int i = fst; i <= lst; i++) {
            pref[i] = (i == fst ? 0 : pref[i - 1]);
            if (s[i] == 'b') pref[i]++, countb++;
        }
        ans2 = 0;
        for (int i = fst; i <= lst; i++) {
            if (s[i] != 'b') {
                ans2 += min(pref[i], countb - pref[i]);
            }
        }
    }

    if (ans1 == LLONG_MAX && ans2 == LLONG_MAX) {
        cout << 0 << "\n";
    } else {
        cout << min(ans1, ans2) << "\n";
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