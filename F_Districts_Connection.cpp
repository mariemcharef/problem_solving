#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<bool> vis;
vector<int> costs;
vector<int> cmp;


void solve() {
    ll n, m, y, x;
    cin >> n;
   
    vector<int>v(n+1);
    set<int> st;
    for(int i = 1; i <= n; i++){
        cin>>v[i];
        st.insert(v[i]);
    }
    if(st.size()==1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int d=-1;
    for (int i = 1; i <= n; i++) {
        if(v[1]!=v[i]){
            d=i;
            cout<<1<<" "<<i<<endl;
        }
    }
    
    for(int i=1;i<=n;i++){
        if(v[i]==v[1]&&i!=1){
            cout<<d<<" "<<i<<endl;
        }
    }

   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}
