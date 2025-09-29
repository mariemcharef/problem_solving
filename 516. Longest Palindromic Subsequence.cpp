#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
         int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n)); 
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int r = 0; r < n; r++) {
            for (int l = n - 1; l >= 0; l--) {
                if (r > l) {
                    break;
                }
                if (l == r) {
                    dp[r][l] =(r - 1 >= 0 && l + 1 < n) ? dp[r - 1][l + 1]+1 : 1;

                } else {
                    if (s[l] == s[r]) {

                        dp[r][l]= (r - 1 >= 0 && l + 1 < n) ? dp[r - 1][l + 1]+2 : 2;
                        
                    } 
                    if(r>0 && dp[r-1][l]>dp[r][l]){
                        dp[r][l]=dp[r-1][l];
                    }
                    if(l<n-1 && dp[r][l+1]>dp[r][l]){
                        dp[r][l]=dp[r][l+1];
                    }
                }
            }
        }
        int res=0;
        for (int r = 0; r < n; r++) {
            for (int l = 0; l < n; l++) {
                int z=dp[r][l];
                res=max(res, z);
                
            }
            cout<<endl;
        }
        return res;
    }
};