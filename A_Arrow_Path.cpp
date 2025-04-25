#include "bits/stdc++.h"
using namespace std;
using  ll =long long;
#define pb push_back
#define mp make_pair

    void solve()
    {
        int n;
        string s,t;
        cin>>n>>s>>t;
        for(int i = 1;i<n;i+=2)
        {
            if(s[i]=='<'&& t[i-1]=='<')
            {
                cout<<"NO\n";
                return;
            }
        }
        for(int i = 1;i<n;i+=2)
        {
            if(s[i]=='<'&&t[i+1]=='<')
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        
        cout<<"YES"<<endl;
        
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