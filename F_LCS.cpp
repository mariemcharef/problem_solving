#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2e7+1; 
vector<int> min_div(MAX_N + 1, 0);
void solve()
{
    string s,t;
    cin>>s>>t;
    int n=s.size(), m=t.size();

  
      
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    string ans="";
    int i=n, j=m;
while(i > 0 && j > 0){
    if(s[i-1] == t[j-1]){
        ans += s[i-1];
        i--;
        j--;
    }
    else if(dp[i-1][j] > dp[i][j-1])
        i--;
    else
        j--;
}
reverse(ans.begin(), ans.end());

    cout<<ans;

    
}


int main()
{
    int tc = 1;
   // cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        solve();
    }


}
