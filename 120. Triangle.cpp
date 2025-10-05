
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==1){
            return triangle[0][0];
        }
        vector<vector<int>> dp(n,vector<int>(n,100000));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                dp[i][j]=triangle[i][j];
                if(j==0){
                    dp[i][j]+=dp[i-1][j];
                }
                else{
                   dp[i][j]+= min(dp[i-1][j],dp[i-1][j-1]);
                }
            }
        }
        int ans=1000000;
        
        for(int i=0;i<n;i++){
            ans=min(ans, dp[n-1][i]);

        }
        return ans;
    }
};