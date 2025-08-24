#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair

ll mod = 1e9 +7;

class DSU {
public:
    vector<int> parent, size;
    vector<set<pair<int,int>>> edges;
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        edges.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;

        }
    }

    int find(int p) {
        if (parent[p] != p) parent[p] = find(parent[p]);
        return parent[p];
    }

    void unionn(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) {
            edges[ra].insert({min(a,b),max(a,b)});
            return;
        }
        if (size[ra] < size[rb]) swap(ra, rb);
        if((size[ra] == size[rb]) && ra>rb)swap(ra, rb);
        edges[ra].insert({min(a,b),max(a,b)});
        for(auto e:edges[rb]){
            edges[ra].insert(e);
        }
        edges[rb].clear();
        parent[rb] = ra;
        size[ra] += size[rb];
    }
};


void solve() {
    int n;
    cin >> n;
    DSU dsu(n);
    ll mx = 0, mn = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
       // if( dsu.find(max(x,i))==min(x,i) && dsu.size[min(x,i)] > 2)mn++;
        dsu.unionn(i, x);

    }

    set<int> parents;
   
    for (int i = 1; i <= n; i++) {
        int pr = dsu.find(i);
        if (parents.insert(pr).second) {
            mx++;
            if(dsu.edges[pr].size()==dsu.size[pr] && dsu.size[pr]>2)mn++;
        }
    }
    if( mn<mx)mn++;
    cout << mn<< " " << mx << "\n";
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}

