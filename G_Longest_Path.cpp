#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> indegree(n+1, 0);
    vector<vector<int>> adj(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    vector<int> dp(n+1,0);

    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);

        }
    }
    int ans=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            dp[v] =max(dp[v], dp[u]+1);
            ans=max(ans, dp[v]);
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);

        }
    }

}
cout<<ans;

}   


int main()
{
    int tc = 1;
    //cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        solve();
    }


}
