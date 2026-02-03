#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    string s;
    cin >> s;
    int m = s.size();

    const int NEG = -1e9;
    vector<vector<int>> dp(m + 1, vector<int>(n, NEG));


    dp[0][k-1] = 0;

    for(int i = 0; i < m; i++){
        for(int pos = 0; pos < n; pos++){
            if(dp[i][pos] == NEG) continue;

            if(s[i] == 'L' || s[i] == '?'){
                int newpos = max(0, pos - 1);
                dp[i+1][newpos] = max(dp[i+1][newpos],
                                      dp[i][pos] + v[newpos]);
            }

            if(s[i] == 'R' || s[i] == '?'){
                int newpos = min(n - 1, pos + 1);
                dp[i+1][newpos] = max(dp[i+1][newpos],
                                      dp[i][pos] + v[newpos]);
            }
        }
    }

    int ans = INT_MIN;
    for(int pos = 0; pos < n; pos++){
        ans = max(ans, dp[m][pos]);
    }

    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
