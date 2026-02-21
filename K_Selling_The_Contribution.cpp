#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod=1e9+7;

void solve()
{
    int n,m,k,x;

    cin >> n >>k;
    vector<int> a(n),b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    set<pair<int,int>> st;

    for(int i=0;i<n;i++){
        st.insert({b[i]-a[i], i});
    }
    auto it=st.rbegin();
    while(k--){
        int idx=it->second;
        a[idx]=b[idx];
        it++;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    

    

}

int main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }


}
