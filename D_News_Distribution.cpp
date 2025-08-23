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
        if(pr1==pr2)return;
        if(rank[pr1]<rank[pr2]) swap(pr1,pr2);
        parent[pr2]=pr1;
        rank[pr1]+=rank[pr2];
        rank[pr2]=0;
    }
};

void solve() {

    int n,q,x,y,m;
    cin >> n>>m;
    DSU dsu(n);

     int ans=0;
    for (int i = 0; i < m; i++){
        int x, y,p;
        cin>>x;
        if(x==0)continue;

        cin>>p;
        x--; 
        while(x){
            cin>>y;
            dsu.unionn(y, p);
            x--;
        }
    
    }
    for(int i=1;i<=n;i++){
        cout<<dsu.rank[dsu.find(i)]<<" ";
    }
    cout<<endl;
    

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    //cin >> tc;
    while (tc--)
    {
        solve();
    }
}

