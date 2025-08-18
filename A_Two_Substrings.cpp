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
    bool ab=0, ba=0;
    for(int i=0;i<n;i++){
        if(! ab && i<n-1 && s[i]=='A' && s[i+1]=='B'){
            ab=1;
            i++;
            continue;
        }
        if(i<n-1 && s[i]=='B' && s[i+1]=='A'){
            ba=1;
            i++;
        }
    }
    if(ab && ba){
        cout<<"YES"<<endl;
        return;
    }
    ab=0, ba=0;
    for(int i=n-1;i>=0;i--){
        
        if(!ab && i>0 && s[i-1]=='A' && s[i]=='B'){
            ab=1;
            i--;
            continue;
        }
        if(!ba && i>0 && s[i-1]=='B' && s[i]=='A'){
            ba=1;
            i--;
            continue;
        }
    }
    if(ab && ba){
        cout<<"YES"<<endl;
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