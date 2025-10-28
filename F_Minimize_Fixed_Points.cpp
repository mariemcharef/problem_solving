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
    vector<int> ans(n+1);
    vector<int> last_pos(n+1);
    for(int i=1;i<=n;i++){
        int a=max_div[i];
        ans[i]=a;
        ans[last_pos[a]]=i;
        last_pos[a]=i;
    
    }
    cout<<1<<" ";
    for(int i=2;i<=n;i++){
        cout<<ans[i]<<" ";
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
