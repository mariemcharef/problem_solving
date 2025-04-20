#include "bits/stdc++.h"
using namespace std;
using  ll =long long;
#define pb push_back
#define mp make_pair

void solve()
{
    ll x,a,b;
    int n,k;
    cin>>n>>k;
    
    map<ll,ll> firstOcc,lastOcc;
    for(int i = 1;i<=n;i++){
        cin>>x;
        if(firstOcc[x]==0){
            firstOcc[x]=i;
        }
        lastOcc[x]=i;

    }
    while(k--){
        cin>>a>>b;
        if(firstOcc[a]>0 &&  firstOcc[a]<lastOcc[b] ){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
    
       
    
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