
#include <bits/stdc++.h>
using namespace std;

long long high(long long a) {
    int pos = -1;
    for (int i = 0; i < 63; ++i)
        if (a & (1LL << i))
            pos = i;
    return pos;
}

void solve() {
    long long a, b;
    cin >> a >> b;
    if(a==b){
        cout<<0<<endl;
        return;
    }
    long long xx = 0;
    int h = high(a);

    for (int i = h; i >= 0; i--) {
        if (!((1LL << i) & a)) {
            xx += (1LL << i);
        }
    }

    long long k = xx ^ a;
    long long xy = 0;

    for (int i = 0; i <= h; i++) {
        if (!((1LL << i) & b)) {
            xy += (1LL << i);
        }
    }

    if ((k ^ xy) == b) {
        cout << 2 << endl;
        cout << xx << " " << xy << endl;
        return;
    }

    cout << -1 << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
            solve();
    }

}
