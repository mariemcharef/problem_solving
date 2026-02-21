#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve() {
    int n;
    cin >> n;

    vector<double> p(n+1);
    for(int i = 1; i <= n; i++)
        cin >> p[i];

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1.0));
    dp [0][0] = 1.0; 
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(dp[i][j] < 0.0) continue;

            int k = i + j + 1;
            if(k > n) continue;

            if(dp[i+1][j] < 0) dp[i+1][j] = 0.0;
            if(dp[i][j+1] < 0) dp[i][j+1] = 0.0;

            dp[i+1][j] += dp[i][j] * p[k];
            dp[i][j+1] += dp[i][j] * (1.0 - p[k]);
        }
    }
    double ans=0.0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i+j==n && i>j)ans+=dp[i][j];
        }
    }
    cout<<setprecision(10)<<ans<<"\n";

    
    
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    //cin >> tc;
    while(tc--)
        solve();
}
