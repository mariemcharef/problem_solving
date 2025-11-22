#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[1005][2005];

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(1005,vector<int> (2005, 0)), pref(n);
        for(int i=0;i<n;i++){
            pref[i].push_back(0);
            int sum=0;
            for(int x:piles[i]){
                sum+=x;
                pref[i].push_back(sum);
            }
        }
        for(int i=0;i<n;i++){
            for(int used=0;used<=k;used++){
                for(int take=0;take<= min((int)piles[i].size(),used);take++){
                    dp[i][used]=max(dp[i][used], 
                    (i==0?0 : dp[i-1][used-take])+pref[i][take] );
                }
            }
        }
        return dp[n-1][k];
        
    }
};
