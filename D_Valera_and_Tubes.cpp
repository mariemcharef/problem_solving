#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> nbChilds;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    int x = 1, y = 1;
    int dir = 1;
    int cnt = 0;

    for (int i = 0; i < k - 1; i++) {
        cout << "2 ";
        cout << x << " " << y << " ";
        cnt++;
        if (dir == 1 && y < m) y++;
        else if (dir == 1 && y == m) x++, dir = -1;
        else if (dir == -1 && y > 1) y--;
        else if (dir == -1 && y == 1) x++, dir = 1;

        cout << x << " " << y << "\n";
        cnt++;
        if (dir == 1 && y < m) y++;
        else if (dir == 1 && y == m) x++, dir = -1;
        else if (dir == -1 && y > 1) y--;
        else if (dir == -1 && y == 1) x++, dir = 1;
    }

    cout << (n * m - 2 * (k - 1)) << " ";
    while (cnt < n * m) {
        cout << x << " " << y << " ";
        cnt++;
        if (dir == 1 && y < m) y++;
        else if (dir == 1 && y == m) x++, dir = -1;
        else if (dir == -1 && y > 1) y--;
        else if (dir == -1 && y == 1) x++, dir = 1;
    }
    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
