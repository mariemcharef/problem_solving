#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    public:
        vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
            map<int,int> mp={{0,0}};
            for(vector<int>& f:flowers){
                mp[f[0]]++;
                mp[f[1]+1]--;
            }
            int cum = 0;
            for(auto& p:mp){
                p.second+=cum;
                cum=p.second;
            }
            vector<int> ans;
            for(int & p:people){
                auto it= mp.lower_bound(p);
                if(it==mp.end() || (*it).first>p) it--;
                ans.push_back((*it).second);
            }
           return ans;
    
        }
    };