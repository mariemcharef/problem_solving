#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod = 998244353;

int dfs(){

}
void solve()
{
    int n, m;
    cin >> n ;
    vector<int> v(n+1);
    int ans=0;
    vector<int> parent(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int gp=1,p=1;
    vector<int> vis(n+1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            gp=i;
            p=i;
            vis[i]=1;
            int depth=0;
            //cout<<p<<" ";
            while(v[p]!=gp ){
                
                p=v[p];
                vis[p]=1;
                depth++;
               // cout<<p<<" ";
            }
           // cout<<depth<<endl;
            ans+=(depth)/2;
            depth=0;
        }  
    }
    cout<<ans<<endl;
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

