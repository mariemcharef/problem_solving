#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
    public:
        string reorganizeString(string s) {
        string ans="";
        int n = s.size();
        vector<char> v(n);
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            if (mp[s[i]] > (n + 1) / 2) {
                return "";
            }
        }
        priority_queue<pair<int, char>> q;
        for (auto e : mp) {
            q.push({e.second, e.first});
        }
        int i = 0;
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int count = p.first;
            char ch = p.second;
            while (count--) {
                if (i >= n) i = 1;
                v[i] = ch;
                i += 2;
            }
        }
        for (int i = 0; i < n; i++) {
            ans+= v[i];
        }
       return ans;
            
        }
    };