#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

void solve()
{
    ll n, x, q;
    string s;
    cin >> s;
    stack<char> st;
    string c = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (!st.empty() && st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        c += st.top();
        st.pop();
    }
    for(int i=c.size()-1;i>=0;i--){
        cout<<c[i];
    }
    
}

int main()
{

    int tc = 1;
    // cin>>tc;
    while (tc--)
    {
        solve();
    }
}