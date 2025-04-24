#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
    public:
        set<string> food;
        set<int> tables;
        map<pair<string,string>,int>mp;
        vector<vector<string>> displayTable(vector<vector<string>>& ord) {
            for(auto o:ord){
                food.insert(o[2]);
                tables.insert(stoi(o[1]));
                mp[{o[1],o[2]}]++;
            }
            vector<vector<string>> ans(tables.size() + 1, vector<string>(food.size() + 1));
            ans[0][0]="Table";
            int i=1;
            for(auto f:food){
                ans[0][i]=f;
                i++;
            }
             i=1;
            for(auto f:tables){
                ans[i][0]=to_string(f);
                i++;
            }
            for(int i=1;i<=tables.size();i++){   
                for(int j=1;j<=food.size();j++){
                    ans[i][j] = to_string(mp[{ans[i][0], ans[0][j]}]);
                }
            }
            return ans;
        }
    };