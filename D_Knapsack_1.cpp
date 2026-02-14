#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2e7+1; 
vector<int> min_div(MAX_N + 1, 0);
void solve()
{
    int n, f_w;
    cin >> n >> f_w;

    vector<int> w(n);
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    vector<ll> dp(f_w+1, 0);

    for (int i = 0; i < n; i++) {
        for (int remaining_w = f_w; remaining_w >= w[i]; remaining_w--) {
            dp[remaining_w] = max(dp[remaining_w],
                                  dp[remaining_w - w[i]] + v[i]);
        }
    }

    cout << dp[f_w] << endl;
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
