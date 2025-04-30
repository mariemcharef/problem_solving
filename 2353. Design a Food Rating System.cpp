
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class FoodRatings {
    public:
    struct compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first != b.first)
                return a.first > b.first; 
            return a.second < b.second;   
        }
    };
        map<string,pair<int,string>> mp1;
        map<string,set<pair<int,string>,compare>> mp2;
        FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
            for(int i=0;i<r.size();i++){
                mp1[f[i]]=make_pair(r[i],c[i]);
                mp2[c[i]].insert(make_pair(r[i],f[i]));
            }
        }
        void changeRating(string f, int n) {
            pair<int,string> t=mp1[f];
            mp2[t.second].erase({t.first,f});
            mp2[t.second].insert({n,f});
            mp1[f]=make_pair(n,t.second);
        }
        string highestRated(string c) {
                auto it = mp2[c].begin();
               string last_first = it->second; 
                return last_first;
            
        }
    };
    
    