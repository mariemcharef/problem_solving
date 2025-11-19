#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
     for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int mx_i=0;
    for(int i=n;i>0;i--){
        if(a[i]==b[i]){
            mx_i=max(mx_i,i);
        }
        if(a[i]==a[i-1]){
            mx_i=max(mx_i,i-1);
        }
        if(b[i]==b[i-1]){
             mx_i=max(mx_i,i-1);
        }
        if(a[i]==a[i-2]){
            mx_i=max(mx_i,i-2);

        }
        if(b[i]==b[i-2]){
            mx_i=max(mx_i,i-2);
        }
    }
     unordered_map<int,int> last_pos_a, last_pos_b;

    for(int i=1;i<=n;i++){
        if(last_pos_b[a[i]]!=0 && i-last_pos_b[a[i]] > 1){
            mx_i=max(mx_i, last_pos_b[a[i]]);
        }
        if(last_pos_a[b[i]]!=0 && i-last_pos_a[b[i]] > 1){
            mx_i=max(mx_i, last_pos_a[b[i]]);
        }
        if(last_pos_a[a[i]]!=0){
            mx_i=max(mx_i, last_pos_a[a[i]]);
        }
        if(last_pos_b[b[i]]!=0){
            mx_i=max(mx_i, last_pos_b[b[i]]);
        }

        last_pos_a[a[i]]=i;
        last_pos_b[b[i]]=i;

    }

    cout<<mx_i<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--){
        solve();

    }
}
