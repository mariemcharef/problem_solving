#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
int mod = 676767677;

typedef long long ll;
 
ll f(ll a, ll b, ll k) {
    ll d = abs(a - b);
    return min(d, k - d);
}

void solve() {
    ll x,n,m,d,k;
    cin>>n;
    vector<int> v(n);
    bool ok=true;
    int pos=-1;
    int pos1=-1;
    bool diff=false;
    for(int i=0;i<n;i++){

        cin>>v[i];
        if(i>0 && abs(v[i]-v[i-1])>1){
            ok=false;
        }
        if(v[i]<1 || v[i]>n){
            ok=false;
        }
        if(v[i]==n)pos=i;
        if(v[i]==1)pos1=i;
        if(i>0 && v[i]!=v[i-1]){
            diff=true;
        }
    }
    if(n==1){
        cout<<"2\n";
        return;
    }
    if(!ok){
        cout<<"0\n";
        return;
    }
    if(pos!=-1){
        vector<int> ans(n);
        for(int i=pos+1;i<n;i++){
            ans[i]=1;
        }
        for(int i=pos-1;i>=0;i--){
            ans[i]=-1;
        }
        if(pos<n-1){
            if(v[pos+1]==v[pos]-1){
                ans[pos]=1;
            }else if(v[pos+1]==v[pos]+1){
                ans[pos]=-1;
            }else{
                ans[pos]=(ans[pos+1]==1 ? -1 : 1);
            }
        }else{
            if(v[pos-1]==v[pos]-1){
                ans[pos]=-1;
            }else if(v[pos-1]==v[pos]+1){
                ans[pos]=1;
            }else{
                ans[pos]=(ans[pos-1]==1 ? -1 : 1);
            }
        }
        vector<int> pref(n+1,0), suff(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+(ans[i]==-1);
        }
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1]+(ans[i]==1);
        }
        vector<int> v1(n,0);
        for(int i=0;i<n;i++){
            int left = (i>0 ? pref[i] : 0);
            int right = (i<n-1 ? suff[i+1] : 0);
            v1[i] = 1 + left + right;
        }
        if(v==v1){
            cout<<"1\n";
        }else{
            cout<<"0\n";
        }

        return;
    }



    if(pos1!=-1){
        pos=pos1;
        vector<int> ans(n);
        for(int i=pos+1;i<n;i++){
            ans[i]=-1;
        }
        for(int i=pos-1;i>=0;i--){
            ans[i]=+1;
        }
        if(pos<n-1){
            if(v[pos+1]==v[pos]-1){
                ans[pos]=1;
            }else if(v[pos+1]==v[pos]+1){
                ans[pos]=-1;
            }
            else{
                ans[pos]=(ans[pos+1]==1 ? -1 : 1);
            }
        }else{
            if(v[pos-1]==v[pos]-1){
                ans[pos]=-1;
            }else if(v[pos-1]==v[pos]+1){
                ans[pos]=1;
            }
            else{
                ans[pos]=(ans[pos-1]==1 ? -1 : 1);
            }
        }
        vector<int> pref(n+1,0), suff(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+(ans[i]==-1);
        }
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1]+(ans[i]==1);
        }
        vector<int> v1(n,0);
        for(int i=0;i<n;i++){
            int left = (i>0 ? pref[i] : 0);
            int right = (i<n-1 ? suff[i+1] : 0);
            v1[i] = 1 + left + right;
        }
        if(v==v1){
            cout<<"1\n";
        }else{
            cout<<"0\n";
        }

        return;
    }

    vector<bool> df(n-1);//df=1 , eq=0
    for(int i=0;i<n-1;i++){
        df[i]=(v[i+1]!=v[i]);
    }
    vector<int> possibility1(n,0), possibility2(n,0);
    possibility1[0]=1;
    possibility2[0]=-1;
    for(int i=1;i<n;i++){
        if(!df[i-1]){
            possibility1[i]=-possibility1[i-1];
            possibility2[i]=-possibility2[i-1];
        }else{
            possibility1[i]=possibility1[i-1];
            possibility2[i]=possibility2[i-1];
        }
    }

    vector<int> pref1(n+1,0), pref2(n+1,0), suff1(n+1,0), suff2(n+1,0);
    for(int i=0;i<n;i++){
        pref1[i+1]=pref1[i]+(possibility1[i]==1);  
        pref2[i+1]=pref2[i]+(possibility2[i]==1);
    }
    for(int i=n-1;i>=0;i--){
        suff1[i]=suff1[i+1]+(possibility1[i]==-1);  
        suff2[i]=suff2[i+1]+(possibility2[i]==-1);
    }
    vector<int> v1(n,0), v2(n,0);
    for(int i=0;i<n;i++){
        int left1 = (i>0 ? pref1[i] : 0);
        int right1 = (i<n-1 ? suff1[i+1] : 0);
        v1[i] = 1 + left1 + right1;
        int left2 = (i>0 ? pref2[i] : 0);
        int right2 = (i<n-1 ? suff2[i+1] : 0);
        v2[i] = 1 + left2 + right2;
    }
    if(v==v1 && v==v2){
        cout<<"2\n";
    }else if(v==v1 || v==v2){   
        cout<<"1\n";
     }else{
        cout<<"0\n";
     }
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
