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

    void update(int pos, int val) {
        for (; pos <= n; pos += pos & -pos)
            tree[pos] += val;
    }

    int getPrefix(int pos) {
        int sum = 0;
        for (; pos > 0; pos -= pos & -pos)
            sum += tree[pos];
        return sum;
    }

    int getRange(int l, int r) {
        if (l > r) return 0;
        return getPrefix(r) - getPrefix(l - 1);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    int mx=0;

    for (int i = 1; i <= n; i++) 
        cin >> a[i], mx = max(mx, a[i]);

    int q;
    cin >> q;

    vector<array<int,3>> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {r, l, i};   // (r, l, index)
    }

    sort(queries.begin(), queries.end());

    FenwickTree fenw(n);

    vector<int> lastPos(mx + 1, 0);
    vector<int> ans(q);

    int curR = 0;
    for (auto &qr : queries) {
        int r = qr[0], l = qr[1], idx = qr[2];

        while (curR < r) {
            curR++;

            int val = a[curR];
            if (lastPos[val] != 0)
                fenw.update(lastPos[val], -1);

            fenw.update(curR, 1);
            lastPos[val] = curR;
        }

        ans[idx] = fenw.getRange(l, r);
    }

    for (int x : ans) 
        cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
