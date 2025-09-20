#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


typedef long long ll;
ll mod = 998244353;
int INF=1e9;

ll pow_2(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n,r,b,a,c,d;
    cin>>n;
   
    vector<int> langueur_vector(n), valid(n);
    set<int> st;
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++){
        cin>>langueur_vector[i];
        v[i].resize(langueur_vector[i]);
        for(int j=0;j<langueur_vector[i];j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<n;i++){
        st.insert(i);
        valid[i]=-1;
    }

    vector<int> ans;
    int cur=-1;
    while(!st.empty()){
        cur++;
        set<int> todelete;
        for(auto& e:st){
            if(langueur_vector[e]<=cur){
                todelete.insert(e);
            }
        }
        for(auto e:todelete){
            st.erase(e);
        }
        if(!st.size()){
            break;
        }

        int mn=INF;

        for(auto& e:st){
            if(valid[e]==cur-1){
                mn=min(mn,v[e][cur]);
            }
        }

        ans.push_back(mn);


        bool reset=0;
        for(auto& e:st ){
            if(valid[e]==cur-1 && v[e][cur]==mn){
                valid[e]=cur;
                if( cur == langueur_vector[e]-1){
                    reset=1;
                }
            }
        }
        if(reset){
            for(auto &u: st){
                valid[u]=cur;
            }
        }
    }

        for(auto& u:ans){
            cout<<u<<" ";
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