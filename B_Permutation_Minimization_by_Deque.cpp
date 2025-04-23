#include "bits/stdc++.h"
using namespace std;
using  ll =long long;
#define pb push_back
#define mp make_pair
void solve() {
    int n;
    cin >> n;
    ll x;
    deque<ll> dq;
   
    for (int i = 0; i < n;i++ ) {
      cin>>x;
      if(x>dq.front()){
        dq.push_back(x);
        
      }else{
        dq.push_front(x);
      }

    }


    for (int i = 0; i < n; i++) {

        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
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