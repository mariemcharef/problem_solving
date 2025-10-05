
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long currP=1ll;
        long long currN=1ll;
        long long g=1ll;
        bool ok=0;
        int mx=-1e9;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            if(nums[i]==0){
                currP=1ll;
                currN=1ll;
                continue;
            }
            long long temp=currP;
            currP=max({currP*nums[i],nums[i]*1ll,currN*nums[i] });
            
            currN=min({currN*nums[i],nums[i]*1ll, temp*nums[i]});

            g=max(g, currP);
        }
        ok=0;
        if(g==1){
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]*nums[i+1]>0){
                    ok=1;
                    break;
                }
            }
            if(!ok)return mx;
        }
        

       return g;
        
    }
};
