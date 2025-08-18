#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;


void solve() {
    string s;
    cin>>s;
    int n=s.size();
    
     if(s[0]==s[n-1]){
        cout<<"NO"<<endl;
        return;
    }
    char fr=s[0],ls=s[n-1];
    for(int i=0;i<n;i++){
        if(s[i]==fr) s[i]='(';
        else if(s[i]==ls) s[i]=')';
    }
    //if char le5er =);
    
    string t=s;
    for(int i=0;i<n;i++){
        if(t[i]!='('  && t[i]!=')')t[i]='(';
    }
    stack<char> st;
    bool ok=1;
    for(int i=0;i<n;i++){
        if(t[i]=='(')st.push(i);
        else{
            if(!st.empty())st.pop();
            else {
                ok=false;
                break;
            } 
        } 
    }
    if(ok && st.empty()){
        cout<<"YES"<<endl;
        return;
    }
    stack<char> st2;
    ok=1;





    t=s;
    for(int i=0;i<n;i++){
        if(t[i]!='('  && t[i]!=')')t[i]=')';
    }
    
    for(int i=0;i<n;i++){
        if(t[i]=='(')st2.push(i);
        else{
            if(!st2.empty())st2.pop();
            else {
                ok=false;
                break;
            } 
        } 
    }

    if(ok && st2.empty()){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}