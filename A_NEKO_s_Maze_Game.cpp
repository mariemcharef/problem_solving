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

    int n,q,x,y;
    cin >> n>>q;
    set<pair<int,int>> blocks;
   
    vector<int> dx={0, 0,1,-1,1,1,-1,-1};
    vector<int> dy={1,-1,0, 0,1,-1,1,-1};
    vector<vector<bool>> filled(2,vector<bool>(n,false));
    for (int i = 0; i < q; i++){
        cin>>x>>y;
        x--,y--;
        if(!filled[x][y]){
            filled[x][y]=1;
            for(int i=0;i<8;i++){
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>=0 && nx<2 && ny>=0 && ny<n){
                    if(nx!=x && abs(y-ny)<=1 && filled[nx][ny]){
                        blocks.insert({nx*n+ny,x*n+y});
                    }
                }
            }
        }
        else{
            filled[x][y]=0;
            for(int i=0;i<8;i++){
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>=0 && nx<2 && ny>=0 && ny<n){
                    if(nx!=x && abs(y-ny)<=1 && filled[nx][ny]){
                        blocks.erase({nx*n+ny,x*n+y});
                        blocks.erase({x*n+y,nx*n+ny});
                    }
                }
            }
        }


         if(!blocks.empty())cout<<"No"<<endl;
         else cout<<"Yes"<<endl;
    }
        
    

}


int main()
{
    int tc=1;
    //cin >> tc;
    while (tc--)
    {
        solve();
    }
}

