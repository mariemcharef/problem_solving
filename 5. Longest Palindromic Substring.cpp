
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n)); 

        for (int r = 0; r < n; r++) {
            for (int l = n - 1; l >= 0; l--) {
                if (r > l) {
                    break;
                }
                if (l == r) {
                    int ans = (r - 1 >= 0 && l + 1 < n) ? dp[r - 1][l + 1]+1 : 1;
                    dp[r][l] = ans;

                } else {
                    if (s[l] == s[r]) {
                        int ans = (r - 1 >= 0 && l + 1 < n) ? dp[r - 1][l + 1]+2 : 2;
                        dp[r][l] = ans;
                    } 
                }
            }
        }

    int res = 0;
    string ans = "";

    for (int r = 0; r < n; r++) {
        if (dp[r][r] > res) {
            res = dp[r][r];
            ans = s.substr(r - dp[r][r]/2, dp[r][r]);
        }

        if (r < n - 1 && dp[r][r+1] > res) {
            res = dp[r][r+1];
            ans = s.substr(r - dp[r][r+1]/2 + 1, dp[r][r+1]);
        }
    }

        return ans;
    }
};
