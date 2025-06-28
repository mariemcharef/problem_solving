#include <bits/stdc++.h>
using namespace std;
using ll = long long;



vector<vector<char>> v;
vector<vector<bool>> vis;
int n, m;

bool dfs(int i, int j, int pi, int pj) {
    if (vis[i][j]) return true;  
    vis[i][j] = true;

    if (i-1 >= 0 && v[i-1][j] == v[i][j] && !(i-1 == pi && j == pj)) {
        if (dfs(i-1, j, i, j)) return true;
    }
    if (j-1 >= 0 && v[i][j-1] == v[i][j] && !(i == pi && j-1 == pj)) {
        if (dfs(i, j-1, i, j)) return true;
    }
    if (i+1 < n && v[i+1][j] == v[i][j] && !(i+1 == pi && j == pj)) {
        if (dfs(i+1, j, i, j)) return true;
    }
    if (j+1 < m && v[i][j+1] == v[i][j] && !(i == pi && j+1 == pj)) {
        if (dfs(i, j+1, i, j)) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    v = vector<vector<char>>(n, vector<char>(m));
    vis = vector<vector<bool>>(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && dfs(i, j, -1, -1)) {  
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
