#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2e7+1; 
vector<int> min_div(MAX_N + 1, 0);

void solve()
{
    ll n,k,p;

    cin >> n>>k;
    vector<int > v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> dp(n,1e9);
    dp[0]=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<=i+k && j<n;j++){
             dp[j]=min(dp[j], dp[i]+abs(v[j]-v[i]));
        
       
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
