#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    ll t,n,m;
    int d,f;
    
        cin>>n>>m;
        string s,c;
        cin>>s;
        set<int> st;
        for(int i=0;i<m;i++){
            int a;
            cin>>a;
            st.insert(a);
        }
        cin>>c;
        vector<char> v;
        for(int i=0;i<m;i++){
            v.push_back(c[i]);
        }
        sort(v.begin(),v.end());
        int k=0;
        for(int j=1;j<=n;j++){
            if(st.find(j)!=st.end()){
                s[j-1]=v[k];
                k++;
            }
        }
        cout<<s<<endl;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}