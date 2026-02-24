#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    string x, y;
    cin >> x >> y;

    vector<int> required(26, 0);
    vector<int> remaining(26, 0);
    vector<int> used(26, 0);

    for (char c : y)
        required[c - 'a']++;

    for (char c : x)
        remaining[c - 'a']++;

    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        char c = x[i];
        remaining[c - 'a']--;

        if (required[c - 'a'] == 0)
            continue; 

        if (used[c - 'a'] == required[c - 'a'])
            continue; 
            
        while (!st.empty())
        {
            char top = st.top();

            if (top >= c)
                break;

            if (remaining[top - 'a'] + used[top - 'a'] - 1 < required[top - 'a'])
                break;

            used[top - 'a']--;
            st.pop();
        }

        st.push(c);
        used[c - 'a']++;
    }

    if (st.size() != m)
    {
        cout << -1 << "\n";
        return;
    }

    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}