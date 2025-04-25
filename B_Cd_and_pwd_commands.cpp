#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m, k;
    cin>>n;
    stack<string> st,sp;
    string cmd ,ch;
    for (int i = 0; i < n; i++) {
        cin>> cmd;
        if(cmd=="pwd"){
            while(!st.empty()){
                sp.push(st.top());
                st.pop();
            }
            cout<<"/";
            while(!sp.empty()){ 
                string c=sp.top();
                cout<<c<<"/";
                st.push(c);
                sp.pop();
                
            }
            cout<<endl;
        }else{
            cin>>ch;
            if (ch[0] == '/') {
                while (!st.empty()) st.pop();
            }
            stringstream ss(ch);
            string token;
            while (getline(ss, token, '/')) {
                if (token.empty()) continue;
                if(token==".."){
                    if (!st.empty()) st.pop();
                }else{
                     st.push(token);
                }
            }

        }
       
    }
   
    
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