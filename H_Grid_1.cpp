#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod=1e9+7;

void solve()
{
    int n,m;

    cin >> n>>m;
    vector<string> grid(n); 
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='#')continue;
            if(i==0 && j==0) continue;
            if(i==0 && j!=0){
                dp[i][j]=dp[i][j-1]%mod;
            }else if(j==0){
                dp[i][j]=dp[i-1][j]%mod;
                
            }else{
                dp[i][j]=(dp[i][j-1]%mod +dp[i-1][j]% mod) % mod;
            }
            
    
        }
    }
    cout<<dp[n-1][m-1];

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
