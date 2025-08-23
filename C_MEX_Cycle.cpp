#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;
ll mod = 998244353;


ll pow_2(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll n,x,y;
    cin >> n>>x>>y;
    vector<ll> mex(n+2);
    if(n%2==1){
        mex[1]=2;
    }
    else{
        mex[1]=1;
    }
    for(int i=2;i<=n;i++){
        if(i%2==1)mex[i]=1;
    }
    if(( x%2!=y%2) || (n%2==1 && (x==1 || y==1) )){
        for(int i=1;i<=n;i++){
                cout<<mex[i]<<" ";
        }
        cout<<endl;
        return;
    }

    if(n%2==0 ){
        set<int> st;
        st.insert(x);
        mex[x]=0;
        if(x==1){
            mex[n]=2;
            st.insert(n);
        }
        else{
            mex[x-1]=2;
            st.insert(x-1);
        }
        if(x==n){
            mex[1]=2;
            st.insert(1);
        }else{
            mex[x+1]=2;
            st.insert(x+1);
        }
        for(int i=1;i<=n;i++){
            if(!st.count(i)){
                if(i%2==x%2)mex[i]=1;
                else mex[i]=0;
            }
        }
        for(int i=1;i<=n;i++){
                cout<<mex[i]<<" ";
        }
        cout<<endl;
        return;
        
    }
    else{
        set<int> st;
        st.insert(x);
        mex[x]=0;
        if(x==n){
            mex[1]=1;
            mex[2]=2;
            st.insert(1),st.insert(2);
        }else if(x==n-1){
            mex[n]=1;
            mex[1]=2;
            st.insert(n),st.insert(1);
        }else{
            mex[x+1]=1,mex[x+2]=2;
            st.insert(x+1),st.insert(x+2);
        }
        
        for(int i=x-1;i>=1;i--){
            if(!st.count(i)){
                if(i%2==x%2)mex[i]=0;
                else mex[i]=1;
            }
        }
        for(int i=x+3;i<=n;i++){
            if(!st.count(i)){
                if(i%2!=x%2)mex[i]=0;
                else mex[i]=1;
            }
        }
        for(int i=1;i<=n;i++){
                cout<<mex[i]<<" ";
        }
        cout<<endl;
        return;
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