#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod = 998244353;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<ll> classrooms(m);
    for (int i = 0; i < m; i++)
    {
        cin >> classrooms[i];
    }

    sort(classrooms.begin(), classrooms.end());

    vector<pair<ll, ll>> grps(n);
    // kol grp bech y5ou pair !=
    int i = 0, j = m - 1;
    for (int k = 0; k < n; k += 2)
    {
        grps[k].first = classrooms[i];
        grps[k].second = classrooms[j];
        if (k < n - 1)
        {
            grps[k + 1].first = classrooms[j];
            grps[k + 1].second = classrooms[i];
        }

        if (j > 0)
            j--;
        if (i < m - 1)
            i++;
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            if (i % 2 == 0)
            {
                cout << grps[j].first << " ";
            }
            else
            {
                cout << grps[j].second << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}
