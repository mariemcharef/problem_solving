#include <bits/stdc++.h>


using namespace std;
using ll = long long;

void solve() {
    int n,m;
    cin >> n>>m;
    set<char> st;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        st.insert(toupper(s[0]));

    }
    bool ok=true;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        for(char c: s){
            if(st.find(toupper(c))==st.end()){
                ok=false;
                
            }
                
        }
    }
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}