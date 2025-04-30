#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    public:
        stack<char> st;
        int minSwaps(string s) {
            int count=0;
            for(int i=0;i<s.size();i++){
                if(s[i]==']' && st.empty()){
                    count++;
                    st.push('[');
                }else if(s[i]=='['){
                    st.push('[');
                }else if(!st.empty() && st.top()=='[' && s[i]==']'){
                    st.pop();
                }
            }
            return (count+st.size()/2)/2;
        }
    };