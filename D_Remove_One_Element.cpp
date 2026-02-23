#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    vector<array<int,2>> dp(n+2, {1, 1});
    dp[1] = {1, 1};

    int ans = 1;
    for(int i = 2; i <= n; i++){
        dp[i][0]=1;
        dp[i][1]=1;
        if(v[i] > v[i-1]){
            dp[i][0]=dp[i-1][0]+1;
            dp[i][1]=dp[i-1][1]+1;
        }

        if(i>2 && v[i]>v[i-2]){
            dp[i][1]=max(dp[i][1], dp[i-2][0]+1);
        }
        if(i==2){
            dp[i][1]=max(dp[i][1], 1);
        }
        ans = max(ans, max(dp[i][0], dp[i][1]) );
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}