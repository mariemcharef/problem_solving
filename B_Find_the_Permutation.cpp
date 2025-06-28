#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,x;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> ans(n,-1),edges_number(n,0);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++) {
            edges_number[i]+=v[i][j]=='1';
        }
    }
    for(int i=0;i<n;i++){
        int count=0;
        int j=n-1;
        while(j>=0 && count<edges_number[i]){
            if(ans[j]==-1)count++;
            j--;
        } 
        while(j>=0 && ans[j]!=-1){
            j--;
        }
        ans[j]=i;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<endl; 
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}