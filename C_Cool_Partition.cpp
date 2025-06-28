#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<bool> vis;
vector<int> costs;
vector<int> cmp;

void dfs(ll node) {
    vis[node] = true;
    cmp.push_back(node);
    for (ll neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor);
        }
    }
}

void solve() {
    ll n, m, y, x;
    cin >> n ;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    int c=0;
    set<int> st,st2;
    st.insert(v[0]);
    int i=0;
    while(i<n){
        while(i<n && !st.empty()){
            st2.insert(v[i]);
            st.erase(v[i]);
            i++;
        }
        if(!st.empty()){
            break;
        }else{
            c++;
            st=st2;
            st2.clear();
        }
    }
    cout<<c<<endl;
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}
