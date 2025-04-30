#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    public:
        map<int,stack<int>>mp;
        long long calculateScore(string s) {
            int n=s.size();
            long long c=0;
            for (int i=0;i<n;i++){
                if(!mp[25 - (s[i] - 'a')].empty()){
                    c+=i-mp[25 - (s[i] - 'a')].top();
                    mp[25 - (s[i] - 'a')].pop();
                }
                else{
                    mp[s[i]-'a'].push(i);
                }
            }
            return c;
        }
    };