#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    public:
        int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
           vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({e[i], s[i]});
        }
        sort(v.begin(), v.end()); 
        long long mx = 0;
        if(k==1){
            for(int i=0;i<n;i++){
                mx=max(1ll*e[i]*s[i],mx);
            }
            return mx % (1000000007);
        }
        k--;
        long long sum=0;
        priority_queue<int,vector<int>,greater<int> > q;
    
        for (int i = n-1; i >=0; i--) {
            long long sp=v[i].second;
            long long mn=v[i].first;
            mx=max(1ll*mn*(sp+sum),mx);
            if(q.size()<k){
                q.push(sp);
                sum+=sp;
            }else if(q.top()<sp){
                sum-=q.top();
                q.pop();
                q.push(sp);
                sum+=sp;
            }
            
        }
    
        return mx % (1000000007);
            
        }
    };