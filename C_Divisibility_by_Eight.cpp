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

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    vector<string> v;
    for(int x=0;x<1000;x+=8){
        string y=to_string(x);
        // while(y.size()<3){
        //     y='0'+y;
        // }
        v.push_back(y);
    }
    bool ok=0;
    string ans;
    for(string x:v){
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i] == x[j]){
                j++;
            }
            if(j==x.size()){
                ok=1;
                ans=x;
                break;
            }
        }
    }
    if(ok){
        cout<<"YES"<<endl;
        cout<<ans;
        return;
    }
    cout<<"NO"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
     //cin >> t;
    while (t--) solve();
    return 0;
}