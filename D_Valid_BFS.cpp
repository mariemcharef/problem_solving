
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<set<ll>> adj;
vector<bool> vis;

void solve() {
    ll n;
    cin >> n;
    adj = vector<set<ll>>(n);
    vis = vector<bool>(n, false);
    
    
    for (int i = 0; i < n-1; i++) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;  
    }

    if (v[0] != 0) {
        cout << "No" << endl;
        return;
    }

    queue<int> q;
    q.push(v[0]);
    vis[v[0]] = true;
    int pos = 1;  

    while (!q.empty() && pos < n) {
        int u = q.front();
        q.pop();

        set<int> children;
        for (int neighbor : adj[u]) {
            if (!vis[neighbor]) {
                children.insert(neighbor);
                vis[neighbor] = true;
            }
        }
        
        for (int i = 0; i < children.size(); i++) {
            if (pos >= n || !children.count(v[pos])) {
                cout << "No" << endl;
                return;
            }
            q.push(v[pos]);
            pos++;
        }
    }
    if (pos != n) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}