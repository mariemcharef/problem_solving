#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    public:
        bool isValid(string s) {
            stack<char>st ;
            for(int i=0;i<s.size();i++){
                if(st.size()<2 || s[i]!='c'){
                    st.push(s[i]);
                }
                else if(s[i]=='c'){
                    char b=st.top();
                    if(b=='b'){
                        st.pop();
                        if(st.top()=='a'){
                            st.pop();
                        }else{
                            st.push('b');
                            st.push('c');
                        }
                    }else{
                        st.push('c');
                    }
                }
            }
            return st.empty();
            
        }
    };