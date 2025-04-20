#include "bits/stdc++.h"
using namespace std;
using  ll =long long;
#define pb push_back
#define mp make_pair

void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    map<string, bool> exists;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        exists[v[i]] = true;
    }

    for (int idx = 0; idx < n; idx++) {
        bool found = false;
        for (int i = 0; i < v[idx].size(); i++) {
            string left = v[idx].substr(0, i);
            string right = v[idx].substr(i);
            if (exists[left] && exists[right]) {
                found = true;
                break;
            }
        }
        cout << (found ? '1' : '0');
    }

    cout << '\n';
}


        


int main()
{
        
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }    
        
}