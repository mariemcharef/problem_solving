#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    public:
        long long maximumSumOfHeights(vector<int>& m) {
            stack<int> st,st1;//npushi index min
            long long ans=0;
            st.push(-1),st1.push(m.size());
            map<int,long long> mp,mp1,leftVal,rightVal;
             int n=m.size();
            mp[-1]=0,mp1[n]=0;
            for(int i=0;i<m.size();i++){
                long long s=0;
                while(st.top()!=-1 && m[st.top()] >m[i]){//awel min 3la ysar
                    st.pop();
                }
                if (st.top() != -1)s+=mp[st.top()];
                s+=1ll*(i-st.top())*m[i];
                mp[i]=s;
                if(st.top() == -1 || m[i]>=m[st.top()]) st.push(i);
                leftVal[i]=s;
            }
    
            for(int i=n-1;i>=0;i--){
                long long s=0;
                while(st1.top()!=n && m[st1.top()] >m[i]){//awel min 3la ymin
                    st1.pop();
                }
                if (st1.top() != n)s+=mp1[st1.top()];
                s+=1ll*(st1.top()-i)*m[i];
                mp1[i]=s;
                if(st1.top() == n || m[i]>=m[st1.top()]) st1.push(i);
                rightVal[i]=s;
                ans=max(rightVal[i]+leftVal[i]-m[i],ans);
            }
            return ans;
        }
    };