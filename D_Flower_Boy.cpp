#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m), pref(n, -1), suf(n, -1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int j = -1;
    for (int i = 0; i < n; i++) {
        if (j + 1 < m && a[i] >= b[j + 1]) {
            j++;
        }
        pref[i] = j;
    }

    if (j == m - 1) {
        cout << 0 << "\n";
        return;
    }


    j = m;
    for (int i = n - 1; i >= 0; i--) {
        if (j - 1 >= 0 && a[i] >= b[j - 1]) {
            j--;
        }
        suf[i] = j;
    }

    long long ans = 1e18;

    if (suf[0] == 1)
        ans = min(ans, (long long)b[0]);

    if (pref[n - 1] == m - 2)
        ans = min(ans, (long long)b[m - 1]);

    for (int i = 1; i < n; i++) {
        if (suf[i] - pref[i - 1] == 2) {
            ans = min(ans, (long long)b[pref[i - 1] + 1]);
        }
    }

    if (ans == 1e18)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}
  


    int main()
    {
        
        int tc=1;
        cin>>tc;
        while(tc--)
        {
            solve();
        }
           
            
        
    }