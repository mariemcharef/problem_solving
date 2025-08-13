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
vector<ll> a;
vector<pair<ll,ll>> mxmn;

void dfs(ll node,int parent) {
    vis[node]=1;

    if(node==0){
        mxmn[0].first=a[0];
        mxmn[0].second=a[0];
    }else{
        ll b = a[node];
        ll c = a[node]- mxmn[parent].first;
        ll d = a[node]- mxmn[parent].second;
        mxmn[node].second = min(min(b,c),d);
        mxmn[node].first = max(max(b,c),d);
    }
    for (ll neighbor : adj[node]) {
        if(!vis[neighbor]){
            dfs(neighbor,node);
        }
    }
}

void solve() {
    ll n, m, y, x;
    cin >> n ;

    adj = vector<vector<ll>>(n);
    vis=vector<bool>(n);
    a=vector<ll>(n);
    mxmn = vector<pair<ll,ll>>(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        x--, y--;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    dfs(0,-1);

    for(int i=0;i<n;i++){
        cout<<mxmn[i].first<<" ";
    }
    
    

    cout<<endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    

     cin >> t;
    while (t--) solve();
    return 0;
}