#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;


void solve() {
    ll t,n,c,d,x,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    vector<ll> p(m),s(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }  
    for(int i=0;i<m;i++){
        cin>>b[i];
    } 
    int j=0;
    for(int i=0;i<m;i++){
        while(j<n && a[j]<b[i]){
            j++;
        }
        p[i]=j;
        j++;
    }
    j=n-1;
    for(int i=m-1;i>=0;i--){
        while(j>=0 && a[j]<b[i]){
            j--;
        }
        s[i]=j;
        j--;
    }

    if(s[0]>=0){
        cout<<0<<endl;
        return;
    }
    set<int> ans;
    for(int i=0;i<m;i++){
        if(i==0 && s[1]>=0){
            ans.insert(i);
        }
        else if(i==m-1 && p[m-1]<=n){
            ans.insert(i);
        }else if(i>0 && i<m-1 && p[i-1]<s[i+1]){
            ans.insert(i);
        }
    }
    if(ans.size()==0){
        cout<<-1<<endl;
        return;
    }
    int answer=b[*(ans.begin())];

    int indice_as8er_wahda=0;
    for(int i:ans){

        if(b[i]<answer){
            indice_as8er_wahda=i;
            answer=b[i];
        }
    }

    j=0;
    for(int i=0;i<m;i++){
        if(i==indice_as8er_wahda)continue;
        while(j<n && a[j]<b[i]){
            j++;
        }
        
    }
    

    cout<<answer<<endl;


    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}