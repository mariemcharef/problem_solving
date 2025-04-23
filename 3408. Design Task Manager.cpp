#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class TaskManager {
    public:
        set<vector<int>> s;
        map<int,pair<int,int>> mp;
        TaskManager(vector<vector<int>>& tasks) {
            for(auto &i:tasks){
                s.insert({i[2],i[1],i[0]});
                mp[i[1]]={i[2],i[0]};
            }
        }
        
        void add(int userId, int taskId, int priority) {
            s.insert({priority,taskId,userId});
            mp[taskId]={priority,userId};
        }
        
        void edit(int t, int n) {
            pair<int,int> c=mp[t];
            s.erase({c.first,t,c.second});
            s.insert({n,t,c.second});
            mp[t].first=n;
        }
        
        void rmv(int t) {
            pair<int,int> c=mp[t];
            s.erase({c.first,t,c.second});
            mp.erase(t);
        }
        
        int execTop() {
            if(s.empty())return -1;
            vector<int> mx=*s.rbegin();
            int u=mx[2];
            int t=mx[1];
            s.erase(mx);
            mp.erase(t);
            return u;
        }
    };
    
   