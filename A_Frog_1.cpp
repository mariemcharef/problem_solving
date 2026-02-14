#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2e7+1; 
vector<int> min_div(MAX_N + 1, 0);

void solve()
{
    ll n,p;

    cin >> n;
    vector<int > v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> dp(n,1e9);
    dp[0]=0;
    for(int i=0;i<n-1;i++){
        
        dp[i+1]=min(dp[i+1], dp[i]+abs(v[i+1]-v[i]));
        if(i+2<n){
            dp[i+2]=min(dp[i+2], dp[i]+abs(v[i+2]-v[i]));
        }
    }
    cout<<dp[n-1]<<endl;
    

}

int main()
{
    int tc = 1;
   // cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        solve();
    }


}
