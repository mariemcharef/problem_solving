    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    const int INF = 1e18;

    int highestBitPos(long long n)
    {
        if (n == 0)
            return -1;
        return (int)log2(n);
    }

    void solve() {
        ll l,r;
        cin >> l >> r;
        ll n=r-l;
        ll m = (1ll<<(highestBitPos(r) +1)) -1;

        if(m==r){
            vector<ll> ans(n+1);
            ll sum=r*(r+1)/2;
            for(ll a=r;a>=1;a--){
                if(m-a<=r)ans[a]=m-a, sum-=(m-a);
                else ans[a]=m/2 - a, sum-= (m/2 -a);
            }
            cout<<r*(r+1)<<endl;
            cout<<sum<<" ";
            for(ll i=1;i<=r;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
            return;

        }
        set<ll> st;
        vector<ll> ans(n+1);
        ll sum=r*(r+1)/2;
        for(ll a=r;a>=2;a--){
            ll b=m;
            while(b-a > r || st.find(b-a)!=st.end())b/=2;
            ans[a]=b-a, sum-=(b-a), st.insert(b-a);
        }
        ll i=1;
        while(st.find(i)!=st.end()){
            i++;
        }
        if(i%2==1){
            ans[0]=i;
            sum-=i;
            ans[1]=sum;
        }else{
            ans[1]=i;
            sum-=i;
            ans[0]=sum;
        }
        

        cout<<r*(r+1)<<endl;
        for(int i=0;i<=r;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;


    }


        

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) solve();
    }
