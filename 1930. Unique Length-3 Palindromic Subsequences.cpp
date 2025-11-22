#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first_occ(26, -1);
        vector<int> last_occ(26, -1);        
        for (int i = 0; i < n; i++) {
            if (first_occ[s[i]-'a']==-1) {
                first_occ[s[i]-'a']=i;
            }
            last_occ[s[i]-'a']=i;
        }
        int ans=0;
        for (int c = 0; c < 26; c++) {
            if (last_occ[c] > first_occ[c]) {
                set<char> st;
                for (int i=first_occ[c]+1;i<last_occ[c];i++) {
                    st.insert(s[i]);
                }
                ans+=st.size();
            }
        }
        
        return ans;
    }
};