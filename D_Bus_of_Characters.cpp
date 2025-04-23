#include "bits/stdc++.h"
using namespace std;
using  ll =long long;
#define pb push_back
#define mp make_pair


void solve() {
    ll n, x,q;
    cin >> n ;
    priority_queue<pair<ll, ll>,vector<pair<ll, ll>>> pq;
    vector<pair<ll,ll>> vec;
    vector<ll> ans(2*n);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        vec.push_back({x,i});
    }
    sort(vec.begin(),vec.end());
    
    string s;
    cin>>s;
    
    int c=0;
    for(int i=0;i<2*n;i++){
        if(s[i]=='0'){
            ans[i]=vec[c].second+1;
            pq.push({vec[c]});
            c++;
        }else{
            ans[i]=pq.top().second+1;
            pq.pop();
        }
    }
    for(int i=0;i<2*n;i++){
        cout<<ans[i]<<" ";
    }
   
 
}

        


int main()
{
        
    int tc=1;
    //cin>>tc;
    while(tc--)
    {
        solve();
    }    
        
}