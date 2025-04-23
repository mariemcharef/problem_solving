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
    int c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (!st.empty() && st.top() == '(' && s[i]==')')
        {
            c+=2;
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    
    cout<<c;
    
    
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