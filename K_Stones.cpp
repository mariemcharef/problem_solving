#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> dp(k + 1, 0);  

    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < n; j++) {
            if(i - v[j] >= 0 && dp[i - v[j]] == 0) {
                dp[i] = 1;
                break;
            }
        }
    }

    if(dp[k])
        cout << "First\n";
    else
        cout << "Second\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    //cin >> tc;
    while(tc--)
        solve();
}
