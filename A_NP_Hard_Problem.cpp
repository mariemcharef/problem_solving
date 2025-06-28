#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<bool> vis;
vector<int> cmp;
set<int> st1,st2;
vector<int> colors;// 1 wela 2

bool dfs(ll node,int color) {
    colors[node]=color;
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
    st1.clear();
    st2.clear();
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    bool ok=true;
    int color=1;
    for (ll i = 0; i < n; i++) {
        color=3-color;
        if(!colors[i] && !dfs(i,color)){
            ok=false;
            break;
        } 
    }
      if(!ok){
          cout<<-1<<endl;
          return;
      }
    for(int i=0;i<n;i++){
        //cout<<i+1<<" : "<<colors[i]<<endl;
        if(colors[i]==1){
            st1.insert(i+1);
        }else if(colors[i]==2){
            st2.insert(i+1);
        }
    }
     cout<<st1.size()<<endl;
     for(int e:st1){
         cout<<e<<" ";
     }
     cout<<endl;
      cout<<st2.size()<<endl;
     for(int e:st2){
         cout<<e<<" ";
     }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
