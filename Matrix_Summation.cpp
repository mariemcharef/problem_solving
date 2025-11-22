#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//fenwick tree 2D
class FenwickTree {
public:
    int n;
    vector<vector<int>> tree;
    vector<vector<int>> grid;
    FenwickTree(int n) : n(n) {
        tree.assign(n + 1, vector<int>(n + 1, 0));
        grid.assign(n + 1, vector<int>(n + 1, 0));
    }

    void update(int x, int y, int val) {
        int old=grid[x][y];
        grid[x][y]=val;
        for (; x <= n; x += x & -x){
            for (int z=y; z <= n; z += z & -z){
                tree[x][z] += val - old;
            }
        }
    }

    int getPrefix(int x ,int y) {
        int sum = 0;
        
        for (; x > 0; x -= x & -x){
            for (int z=y; z > 0; z -= z & -z){
                  sum += tree[x][z];
            }
          
        }
            
        return sum;
    }

    int getRange(int a,int b, int c, int d) {
        
        return getPrefix(c,d) + getPrefix(a-1 , b-1) - getPrefix(c, b-1) - getPrefix(a-1, d);
    }
};

void solve() {
    int n;
    cin >> n;
    string s;
    FenwickTree f(n);
    while(1){
        cin>>s;
        if(s[0]=='E'){
            break;
        }
        if(s=="SET"){
            int x, y, num;
            cin>>x>>y>>num;
            f.update(x+1,y+1,num);
        }else{
            int a, b, c, d;
            cin>>a>>b>>c>>d;
            
            cout<<f.getRange(a+1,b+1,c+1,d+1)<<"\n";
        }
    }

    cout<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
