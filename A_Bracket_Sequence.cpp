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
        if(s[i]=='(' || s[i]=='['){
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
        else if(s[i]==']'){
            if(!st.empty() && s[st.top()]=='['){
                st.pop();
            }
            else{
                st.push(i);
            }
        }
    }
    int r=n;
    int mx=0;
    int count=0;
    string ans="";
    while(!st.empty()){
       // cout<<st.top()<<" ";
        count=0;
        int l=st.top();
        for(int i=l+1;i<r;i++){
            if(s[i]=='[') count++;
        }
        if(count>mx){
            mx=count;
            ans=s.substr(l+1,r-l-1);
        }
        r=l;
        st.pop();
    }
    cout<<mx<<endl;
    cout<<ans;
    
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