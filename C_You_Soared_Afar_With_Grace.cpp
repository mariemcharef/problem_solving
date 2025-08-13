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
    cin >> n;
    bool ok=1;
    int c=0;
    vector<int>  a(n),b(n),voisins(n+1);
    map<int,int> pos_a,pos_b;
    for (int i = 0; i < n; i++){
        cin>>a[i];
        pos_a[a[i]]=i;
    }
    for (int i = 0; i < n; i++){
        cin>>b[i];
        voisins[a[i]]=b[i];
        voisins[b[i]]=a[i];
        pos_b[b[i]]=i;
        if(a[i]==b[i] && n%2==1){
            c++;
        }
        if(a[i]==b[i] && n%2==0){
            ok=0;
        }

    }
    if(!ok || c>1){
        cout<<-1<<endl;
        return;
    }
    for (int i = 0; i < n; i++){
        if (a[i]!=voisins[b[i]]){
            cout<<-1<<endl;
            return;
        }
    }
 
    vector<pair<int,int>> ans;
    set<pair<int,int>> ans1;
    for(int i=0;i<n;i++){
        if(a[i]==b[i] && i!=n/2){
            int k=n/2;
            if(ans1.insert({min(k,i),max(k,i)}).second){
                ans.push_back({min(k,i),max(k,i)});
            }
            int x=a[i];


            a[i]=a[k];
            pos_a[a[k]]=i;
            b[i]=b[k];
            pos_b[b[i]]=i;
            a[k]=x,b[k]=x;
            pos_a[x]=k,pos_b[x]=k;
            continue;
        };
        if(b[n-1-i]!=a[i]){
            int k=pos_b[a[i]];
            if(ans1.insert({min(k,n-i-1),max(k,n-i-1)}).second){
                ans.push_back({min(k,n-i-1),max(k,n-i-1)});
            }
            a[k]=a[n-1-i];
            pos_a[a[n-i-1]]=k;
            b[k]=b[n-i-1];
            pos_b[b[n-i-1]]=k;

            a[n-i-1]=b[i];
            pos_a[b[i]]=n-1-i;
            b[n-i-1]=a[i];
            pos_b[a[i]]=n-1-i;

        }
    }
    
     cout<<ans.size()<<endl;
     for(auto e:ans){
         cout<<e.first+1<<" "<<e.second+1<<endl;
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

