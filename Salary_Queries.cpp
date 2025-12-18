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

    ll n,q,m,x,y;
    cin >> n>>q;
    ordered_multiset<ll> st;
    st.insert(1e9+1);
    vector<long long> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i]; 
        st.insert(v[i]);
    }
    while(q--){
        char c;
        ll a,b;
        cin>> c;
        if(c=='?'){
            cin>>a>>b;
            int it1= st.order_of_key(a), it2=st.order_of_key(b+1);
            cout<<it2- it1<<"\n";

        }else{
            int pos;
            ll val;
            cin>> pos>> val;
            pos--;
            int oldVal=v[pos];
            v[pos]=val;
            int idx = st.order_of_key(oldVal);      
            st.erase(st.find_by_order(idx)); 
            
            st.insert(val);
        }
    }
    

}


int main()
{
    int tc=1;
   // cin >> tc;
    while (tc--)
    {
        solve();
    }
}

