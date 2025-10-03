#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    ll n, h;
    cin >> n;
    string s;
    cin>>s;
    vector<bool> v(n+1);
    for(int i=0;i<n;i++){
        v[i+1]=(s[i]=='1');
    }
    vector<int> cost(n+1,0);

    for(int i = n; i>=1; i--) {
        for (int j = i; j <= n; j += i) {
            if(v[j])break;
            else {
                cost[j]=i;
            }
        }
    }
    int ans=0;

    for(int i=1;i<=n;i++){
        if(!v[i]){
            ans+=cost[i];
        }
    }
    cout<<ans<<endl;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q = 1;
     cin >> q;
    while (q--)
    {
        solve();
    }
}