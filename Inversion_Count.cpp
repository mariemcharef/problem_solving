#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



class FenwickTree {
public:
    int n;
    vector<int> tree;

    FenwickTree(int n) : n(n) {
        tree.assign(n + 1, 0);
    }

    void update(int pos, ll val) {
        for (; pos <= n; pos += pos & -pos) {
            tree[pos] += val;
        }
    }

    ll getPrefix(int pos) {
        ll sum = 0;
        for (; pos > 0; pos -= pos & (-pos)) {
            sum += tree[pos];
        }
        return sum;
    }

    ll getRange(int l, int r) {
        if (l > r) return 0;
        if (l == 1) return getPrefix(r);
        return getPrefix(r) - getPrefix(l -1);
    }

};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    int mx=0;
    for (int i = 1; i <=n; i++) cin >> a[i],mx=max(mx, a[i]);

    FenwickTree f(mx);

    ll ans = 0;
    for (int r = n ; r >= 1; r--) {

        ans += f.getRange(1,a[r]-1);
        f.update(a[r], 1);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
