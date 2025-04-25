#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    string s,t,u;
    cin >> s;
    ll n = s.size();
    set<pair<char, int>> v;
    vector<int> vec(n,1e9);
    stack<int> st;
    vec[n-1]=s[n-1]-'a';
    for (int i = n-2; i >= 0; i--) {
        vec[i]=min(s[i]-'a',vec[i+1]);
    }
    for(int i=0;i<n;i++){
        int cur=s[i]-'a';
        while(t.size() && t.back()-'a'<=vec[i]){
                u+=t.back();
                t.pop_back();
        }
        if(cur==vec[i]){//as8er wahda
            
            u+=s[i];
        }else{
            t+=s[i];
        }   
    }
    while(t.size()){
        u+=t.back();
        t.pop_back();
    }
    cout<<u<<endl;

    
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