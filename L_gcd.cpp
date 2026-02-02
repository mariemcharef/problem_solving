#include <bits/stdc++.h>
using namespace std;

void generatePermutations(vector<string>& v,
                          vector<bool>& used,
                          vector<string>& current,
                          vector<vector<string>>& ans,
                          int k) {

    if (current.size() == k) {
        ans.push_back(current);
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(v[i]);

            generatePermutations(v, used, current, ans, k);

            current.pop_back();
            used[i] = false;
        }
    }
}
int _gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void solve(){
    int n, k;
    cin >> n;
    vector<int> v(n),suf(n+1), pref(n+1);
    int gcd;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i==0){
            gcd = v[i];
            pref[0]=v[i];
            continue;
        }
        pref[i] = _gcd(pref[i-1], v[i]);
        
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            suf[i]=v[i];
            continue;
        }
        suf[i] = _gcd(suf[i+1], v[i]);
    }
    set<int> st;
    for (int i = 0; i < n; i++) {
        int g;
        if (i == 0) g = suf[1];
        else if (i == n - 1) g = pref[n - 2];
        else g = _gcd(pref[i - 1], suf[i + 1]);

        st.insert(g);
    }

    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        bool ok=false;
        for(auto &it: st){
            if(it%x==0 ){
                cout<<"YES\n";
                ok=true;
                break;
            }
        }
        
        if(!ok)  cout<<"NO\n";   
        
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
