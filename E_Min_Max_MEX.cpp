#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}
bool f(vector<ll>& v,int k,int x){
    int count=0;
    set<ll> st;
    int i=0;
    while(i<v.size()  &&  st.size()<x){
        if(v[i]<x){
            st.insert(v[i]);
        }
        if(st.size()==x){
            count++;
            st.clear();
        }
        i++;
    }
    return count>=k;

}


void solve() {
    int n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int l=0,r=2*1e5;

    while(l<r){
        int mid=l + (r - l + 1) / 2;
        if(f(v,k,mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}