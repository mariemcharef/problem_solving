
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


class BrowserHistory {
    public:
        vector<string> v;
        int pos=0;
        BrowserHistory(string homepage) {
            v.push_back(homepage);
        }
        
        void visit(string url) {
            v.erase(v.begin() + pos+1, v.end());
            v.push_back(url);
            pos++;
        }
        
        string back(int steps) {
            pos = max(0, pos - steps); 
        return v[pos]; 
            
        }
        
        string forward(int steps) {
             pos = min((int)v.size() - 1, pos + steps); 
        return v[pos]; 
        }
    };
    
   