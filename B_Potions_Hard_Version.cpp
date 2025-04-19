#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,x;
    cin >> n;
    
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    ll s=0;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        s+=x;
        pq.push(x);
        while(s<0){
            s-=pq.top();
            pq.pop();
        }   
    }
    cout <<(int)pq.size()<< endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}