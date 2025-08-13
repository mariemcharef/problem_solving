#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod = 998244353;

void solve()
{
    int n, m;
    cin >> n ;
    vector<int> d(n),r(n),l(n);
 
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for(int i=0;i<n;i++){
        cin>>l[i];
        cin>>r[i];
    }

    vector<int> jokers;
    int left=0;
    for(int i=0;i<n;i++){
        if(d[i]==-1){
            jokers.push_back(i);
        }else{
            left+=d[i];
        }
        while(left<l[i]){
            if(jokers.empty()){
                cout<<-1<<endl;
                return;
            }
            d[jokers.back()]=1;
            left++;
            jokers.pop_back();
        }
        while (left + jokers.size() > r[i]) {
            if (jokers.empty()) {
                cout << -1 << '\n';
                return;
            }
            d[jokers.back()] = 0;
            jokers.pop_back();
        }
    }
    for(auto e:d){
        if(e==-1)cout<<0<<" ";
        else cout<<e<<" ";
    }
    cout<<endl;
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

