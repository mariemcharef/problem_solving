#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m, k;
    string s;
    cin>>s;
    stack<int> st;
    st.push(-1);
    n=s.size();
    for (int i = 0; i < n; i++) {
        if(s[i]=='(' ){
            st.push(i);
        }
        else if(!st.empty() && s[i]==')'){
            if(s[st.top()]=='('){
                st.pop();
            }
            else{
                st.push(i);
            }
        }
    }
    int r=n;
    map<int,int> mp;
    int mx=0;
    int count=0;

    while(!st.empty()){
        count=0;
        int l=st.top();
        for(int i=l+1;i<r;i++){
            if(s[i]=='(') count+=2;
        }
        if(count>=mx){
            mx=count;
            mp[mx]++;
 
        }
        r=l;
        st.pop();
    }
    if(mx==0){
        cout<<0<<" "<<1;
        return;
    }
    cout<<mx<<" ";
    cout<<mp[mx];
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}