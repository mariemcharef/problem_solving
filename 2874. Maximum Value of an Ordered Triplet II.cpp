#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
    public:
        long long maximumTripletValue(vector<int>& v) {
            int n=v.size();
            vector<int> v0(n),v1(n);
            v0[n-1]=v[n-1];
            for(int i=n-2;i>=0;i--){
                v0[i]=max(v[i],v0[i+1]);
            }
            v1[0]=v[0];
            for(int i=1;i<n;i++){
                v1[i]=max(v[i],v1[i-1]);
            }
            long long ans=0;
            for(int i=1;i<n-1;i++){
                ans=max(ans,(1ll*v1[i-1]-v[i])*v0[i+1] );
            }
            return ans;
        }
    };