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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long combination_factorial(int n, int k) {
    if (k > n || k < 0) return 0;
    if (k == 0 || k == n) return 1;
    
    long long n_factorial = factorial(n);
    long long k_factorial = factorial(k);
    long long nk_factorial = factorial(n - k);
    
    return n_factorial / (k_factorial * nk_factorial);
}

pair<long long,long long> greatest_divisor_pair(long long b, long long n) {
    long long best = -1;
    pair<long long,long long> ans = {-1,-1};

    for (long long i = 1; i * i <= b; i++) {
        if (b % i == 0) {
            long long d1 = i;
            long long d2 = b / i;

            if (d1 < n && d1 > best) {
                best = d1;
                ans = {d1, d2};
            }
            if (d2 < n && d2 > best) {
                best = d2;
                ans = {d2, d1};
            }
        }
    }
    return ans;
}
void solve() {
    long long x,a,b,k,n;
    cin >> a >> b;
    if(a==1 && b%2==1){
        cout<<a+b<<"\n";
        return;
    }
    if(b==1 && a%2==0){
        cout<<-1<<"\n";
        return;
    }

    if((b*a) %2==1){
        cout<<a*b+1<<"\n";
        return;
    }
    if(b%2==0 && a%2==0){
        cout<<2+(b/2)*a<<"\n";
        return;
    }
    if(b%2==0 && a%2==1){
        if(b/2 %2==1){
            cout<<-1<<"\n";
            return;
        }else{
            cout<<2+(b/2)*a<<"\n";
            return;
        }

    }
    if(b%2==1 && a%2==0){
        cout<<-1<<"\n";
        return;
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