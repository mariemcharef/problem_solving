#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;

ll mod = 1e9 +7;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void solve() {
    int k,n;
    cin>>n;
    
    vector<ll> v(n+1, 0), mnpos;
    ll mn=mod;
    for (int i = 0; i < n; i++){
        cin>>v[i];
        mn=min(mn, v[i]);
    }
    int mx=0;
    for (int i = 0; i < n; i++){
        if(v[i]==mn) mnpos.push_back(i);
    }
    if(mnpos.size()==1) mx=max(mx, n-1);
    for(int i=1;i<mnpos.size(); i++){
        mx=max(mx, (int)(mnpos[i]-mnpos[i-1])-1);
    }
    mx=max(mx,(int) (mnpos[0]+n-mnpos.back()-1));
        
    cout<<n*mn+ mx;
}



int main()
{
    int tc=1;
    //cin >> tc;
    while (tc--)
    {
        solve();
    }
}

