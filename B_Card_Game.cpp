#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;

int comp(int a,int b){
    if(a>b)return 1;
    else if(a==b) return 0;
    else return -1;
}
void solve() {
   
    vector<int> a(2),b(2);
    for(int i=0;i<2;i++){
        cin>>a[i];
    }
    for(int i=0;i<2;i++){
        cin>>b[i];
    }
    int ans=0;
    if(comp(a[0],b[0]) + comp(a[1],b[1])>0){
        ans++;
    }
    if(comp(a[0],b[1]) + comp(a[1],b[0])>0){
        ans++;
    }
    if(comp(a[1],b[0]) + comp(a[0],b[1])>0){
        ans++;
    }
    if(comp(a[1],b[1]) + comp(a[0],b[0])>0){
        ans++;
    }
    cout<<ans<<endl;



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}