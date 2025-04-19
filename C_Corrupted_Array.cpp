#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    ll t,n,m;
    cin>>n;
    n+=2;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    //if sum =v[n-2]=> x=v[n-1]
    ll s=0;
    for(int i=0;i<n-2;i++){
        s+=v[i];
    }
    if(s==v[n-2]){
        for(int i=0;i<n-2;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //sum= v[n-1]=> search x
    s+=v[n-2];
    
    for(int i=0;i<n-1;i++){
        if(s-v[i]==v[n-1]){//v[i]=x
            for (int j = 0; j < n - 1; j++) {
                if (j != i) cout << v[j] << " ";
            }
            cout<<endl;
            return;
        }
    }
    cout<<-1<<endl;
       
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}