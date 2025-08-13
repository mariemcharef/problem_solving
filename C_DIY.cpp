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
    vector<int> v;
    map<int,int> mp;
 
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(auto e:mp){
        if (e.second >1){
            int nb=e.second/2;
            while(nb--){
                v.push_back(e.first);
            }
        }
    }
    if(v.size()<4){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    sort(v.begin(),v.end());
     m=v.size();
    int v1=v[0],v2=v[1],v3=v[m-2],v4=v[m-1]; 
    ll dx=1LL*(v2-v1)*(v4-v3);
    ll dy =1LL*(v4-v2)*(v3-v1);
     if(dx >= dy){
         cout<<v1<<" "<<v3<<" "<<v2<<" "<<v3<<" "<<v1<<" "<<v4<<" "<<v2<<" "<<v4<<endl;
     }else{
         cout<<v1<<" "<<v2<<" "<<v3<<" "<<v2<<" "<<v1<<" "<<v4<<" "<<v3<<" "<<v4<<endl;
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

