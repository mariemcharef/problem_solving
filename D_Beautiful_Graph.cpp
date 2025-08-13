#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = int(3e5) + 999;
const int MOD = 998244353;

int n, m;
vector <int> g[N];
int p2[N];

vector<vector<ll>> adj;
vector<bool> vis;
vector<int> cmp;
set<int> st1,st2;
vector<int> colors;// 1 wela 2

bool dfs(ll node,int color) {
    colors[node]=color;
    if(color==1)st1.insert(node);
    else st2.insert(node);
    for (ll neighbor : adj[node]) {
        if(colors[neighbor]==color){
            return false;
        }
        if (!colors[neighbor])
            if (!dfs(neighbor, 3 - color)) {
                return false;
            }
    }
    return true;
   
}

void solve() {
    
    
    ll n, m, y, x;
    cin >> n >> m;

    adj = vector<vector<ll>>(n);
    colors=vector<int>(n,0);
    vis=vector<bool>(n);
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    ll ans = 1;
    bool ok=true;
    for(int i=0;i<n;i++){
        if(!colors[i]){
            st1.clear();
            st2.clear();
            if (!dfs(i, 1)) {
                ok = false;
                
            }
            ll a = st1.size();
            ll b = st2.size();
            ll cur = (p2[a] + p2[b]) % MOD;
            ans = (ans * cur) % MOD;
        }
        

    }
 

    
    if(!ok){
        cout<<0<<endl;
        return;
    }
    cout<<ans<<endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    p2[0] = 1;
    for(int i = 1; i < N; ++i)
    	p2[i] = (2 * p2[i - 1]) % MOD;

     cin >> t;
    while (t--) solve();
    return 0;
}