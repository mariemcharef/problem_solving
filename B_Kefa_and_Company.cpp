#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n,d;
    cin >> n>>d;
    vector<pair<ll,ll>> a(n);
    ll  sum=0;
    for (ll i = 0; i < n ; i++) {
        cin >> a[i].first;
        cin>>a[i].second;
    }
    sort(a.begin(),a.end());
    int i=0,j=0;
    sum=a[0].second;
    ll mx=a[0].second;

    while(j<n-1){
        if(a[j+1].first-a[i].first<d){
            j++;
            sum+=a[j].second;
        }
        else{
            sum-=a[i].second;
            i++;
        }
        mx=max(mx,sum);

    }
    cout<<mx;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin >> t;
    while (t--) solve();
}
