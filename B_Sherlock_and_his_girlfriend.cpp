#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;



const int MAXN = 1e7;

vector<int> is_prime(MAXN + 1,1) ;
int pref[MAXN + 1];

void sieve() {

    for (int i = 2; i * i <= MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i)
                is_prime[j] = 0;
        }
    }
}

vector<int> good(MAXN + 1, 0);

void precompute() {
    for (long long y = 1; y*y*y*y <= MAXN; y++) {
        long long y4 = y*y*y*y;
        for (long long x = 1; x*x + y4 <= MAXN; x++) {
            long long v = x*x + y4;
            if (is_prime[v])
                good[v] = 1;
        }
    }

    for (int i = 1; i <= MAXN; i++) {
        pref[i] = pref[i-1] + good[i];
    }
}

bool isPrime(long long x) {
    if(x>1e7)return false;
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (long long i = 5; i * i <= x; i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}

void solve() {

    int n;
    cin >> n;
    int ans=0;
    if(n<=2){
        cout<<1<<"\n";
        for(int i=2;i<=n+1;i++){
            cout<<1<<" ";
        }

        return;
    }
    cout<<2<<"\n";
    for(int i=2;i<=n+1;i++){
        if(isPrime(i)){
            cout<<1<<" ";

        }else{
            cout<<2<<" ";
            
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1, n;
    //cin >> T;
    while (T--) {
        solve();
    }
}
