#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<bool> vis;
vector<bool> cats;
int m;
int ans = 0;


void solve() {
    int n, x, y;
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    vis[0];
    q.push(0);
    bool mid=false;
    vector<int> bgadech_marbouta(n,0);
    bgadech_marbouta[0]=adj[0].size();
    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis[x]=true;
        for(int e:adj[x]){
            if(!vis[e]) q.push(e);
            bgadech_marbouta[e]=adj[e].size();
        }
    }  
    int c_1=0;
    int c_2=0;
    for(int i=0;i<n;i++){
        if(bgadech_marbouta[i]==1){
            c_1++;
        }
        if(bgadech_marbouta[i]==2){
            c_2++;
        }
        if(bgadech_marbouta[i]==0){
            cout<<"unknown topology"<<endl;
            return;
        }
    }
    //cout<<c_1<<" "<<c_2<<endl;
    if(c_1 ==2 && c_2==n-2 && n!=m ){
        cout<<"bus topology"<<endl;
        return;
    }
    if( c_2==n && n==m){
        cout<<"ring topology"<<endl;
        return;
    }
    if(c_1 ==n-1){
        cout<<"star topology"<<endl;
        return;
    }
    cout<<"unknown topology"<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
