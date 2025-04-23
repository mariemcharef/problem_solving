#include "bits/stdc++.h"
using namespace std;
using  ll =long long;
#define pb push_back
#define mp make_pair
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> v(n + 1, 0);
    stack<ll> st;
    int num=0;
    for (ll i = 0; i < s.size();i++ ) {
        if (isdigit(s[i])) {
            num=10*num+(s[i]-'0');
        }
        else if (s[i] == ')') {
            
            if (!st.empty()) {
                v[num] = st.top();
            }
            if(num==0) st.pop();
            num=0;
        }else{
            if(!st.empty()) v[num]=st.top();
            if(num!=0)st.push(num);
           
            num=0;
        }
    }

    for (ll i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


        


int main()
{
        
    int tc=1;
    //cin>>tc;
    while(tc--)
    {
        solve();
    }    
        
}