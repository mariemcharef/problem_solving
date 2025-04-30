#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
    public:
        set<pair<long long ,long long>> st;
        map<long long,long long> m;
        vector<long long> mostFrequentIDs(vector<int>& v, vector<int>& f) {
            
        int n = v.size();
        vector<long long> ans(n);
            for(int i=0;i<n;i++){
                if(m[v[i]]>0){
                    st.erase({m[v[i]],v[i]});
                }
                m[v[i]]+=f[i];
                if(m[v[i]]>0) {
                    st.insert({m[v[i]],v[i]});
                    }
                if(!st.empty()){
                    auto it=st.rbegin();
                    long long a=it->first;
                    ans[i]=a;
                } else{
                    ans[i]=0;
                }
            }
            return ans;
        }
            
    };