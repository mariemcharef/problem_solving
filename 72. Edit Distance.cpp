#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        if(n==0)return m;
        if(m==0)return n;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 1000));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    int res=min(dp[i-1][j], dp[i-1][j-1]);
                    dp[i][j]=min(dp[i][j-1], res)+1;
                    
                }
            }
        }
        return dp[n][m];
    }

};