#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const int MAX_N = 1e7; 
vector<int> max_div(MAX_N + 1, 0);
vector<ll> premiers;
vector<ll> pref_premiers;

void seive() {
    for (int i = 2; i <= MAX_N; i++) {
        if (max_div[i] == 0) {
            for (int j = i; j <= MAX_N; j += i) {
                max_div[j] = i;
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    int p=0,ip=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]%2)ip++;
        else p++;
    }
    if(p && ip){
        sort(v.begin(), v.end());
    }
    for(int i:v){
        cout<<i<<" ";
    }

   
    cout<<endl;

    
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    seive();
    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}
