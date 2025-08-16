#include <bits/stdc++.h>
using namespace std;

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

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<vector<int>> tot;
        vector<bool>ans(queries.size(),0);
        DSU dsu(n);
        int i=0;
        for(auto e: edgeList){
            tot.push_back({e[2],0, 0,e[0],e[1]});
        }
        for(auto e: queries){
            tot.push_back({e[2],-1,i,e[0],e[1]});
            i++;
        }
        sort(tot.begin(),tot.end());
        for(auto e: tot){
            if(e[1]==-1){
                if(dsu.find(e[3]) == dsu.find(e[4])){
                    ans[e[2]]=true;
                }
            }else{
                dsu.unionn(e[3],e[4]);
            }
        }
        return ans;
    }
};