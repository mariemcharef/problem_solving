#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
    public:
    
        int largestRectangleArea(vector<int>& h) {
            int n=h.size();
            stack<int> st;
            int ans=0;
            vector<int> next(n,n),prev(n,-1);
            for(int i=0;i<n;i++){
                while(!st.empty() && h[i]<h[st.top()]){
                    next[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && h[i]<h[st.top()]){
                    prev[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
             for(int i=0;i<n;i++){
                ans=max(ans,(next[i]-prev[i]-1)*h[i]);
             }
            return ans;
        }
    };