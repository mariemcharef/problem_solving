

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        int n=dict.size();
        int m=s.size();
        vector<bool> dp(m+1);
        dp[0]=1;
        for(int i=0;i<=m;i++){
            for(string e:dict){
                int u=e.size();
                if(i>=u){
                    string sbstr=s.substr(i-u,u);
                    if(e==sbstr && dp[i-u]){
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        
        return dp[m];
    }
};
