#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod = 1e9 +7;
class DSU{
public:
    vector<int> parent,rank;

    DSU(int n){
        parent=vector<int>(n+1);
        rank=vector<int>(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }
    int find(int p){
        if(parent[p]!=p){
            return parent[p]=find(parent[p]);
        }
        return parent[p]=p;
    }
    void unionn(int e1,int e2){
        int pr1=find(e1), pr2=find(e2);
        if(rank[pr1]<rank[pr2]) swap(pr1,pr2);
        parent[pr2]=pr1;
        rank[pr1]+=rank[pr2];
        rank[pr2]=0;
    }
};
long long modpow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

void solve() {
    int n, q, k, x, y;
    cin >> n >> k;
    multiset<int> s, t;

    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x % k);
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        int modx = x % k;
        auto it = s.find(modx);
        if (it != s.end()) {
            s.erase(it); 
        } else {
            t.insert(modx);
        }
    }
    if (!s.empty()) {
        vector<int> transformed;
        for (int e : s) {
            transformed.push_back((k - e) % k);
        }
        s.clear();
        for (int e : transformed) s.insert(e);
        for (int e : t) {
            auto it = s.find(e);
            if (it != s.end()) s.erase(it);
        }
    }

    if (!s.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}



int main()
{
    int tc=1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}

