#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(string s){
        int n=s.size();
        for(int i=0;i<(n+1)/2;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<vector<string>>> dp(n+1); 
        dp[0].push_back({});
        for(int i=1;i<=n;i++){
            for(int len=1;len<=i;len++){
                string w=s.substr(i-len,len);
                
                if(check(w)){
                    for(auto prev:dp[i-len]){
                        auto temp=prev;
                        temp.push_back(w);
                        dp[i].push_back(temp);
                        
                    }
                    
                }
                
            }

        }
       
        return dp[n];
    
    }
};

int main(){
    Solution s=Solution();
    cout<<1<<2<<3;
    s.partition("abcabaca");
    return 0;
}