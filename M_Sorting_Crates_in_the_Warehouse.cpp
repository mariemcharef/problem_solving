#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_multiset;

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> vec(n, 0);
    ordered_multiset st;

    int id = 0;
    bool ok = true;

    for(int i = 0; i < n; i++)
    {
        int greater_count = st.size() - st.order_of_key({v[i], INT_MAX});
        vec[i] = greater_count;

        st.insert({v[i], id++});
    }

    st.clear();

    for(int i = n - 1; i >= 0; i--)
    {
        int smaller_count = st.order_of_key({v[i], 0});
        vec[i] += smaller_count;

        if(vec[i] % 2 == 1)
        {
            ok = false;
            break;
        }

        st.insert({v[i], id++});
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}
