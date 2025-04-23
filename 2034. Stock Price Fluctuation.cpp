#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class StockPrice {
    public:
        int mx=0,mn;
        multiset<int> s;//min w max
        map<int,int> mp;//key time, value old price
        StockPrice() {
        }
        
        void update(int t, int p) {
            if(mp[t]>0){
                int old=mp[t];
                s.erase(s.lower_bound(old));//i'm sure that the value exists in s
            }
            mp[t]=p;
            s.insert(p);
            mx=max(mx,t);
        }
        
        int current() {
            return mp[mx];
        }
        
        int maximum() {
            return *s.rbegin();
        }
        
        int minimum() {
            return *s.begin();
            
        }
    };
    
    /**
     * Your StockPrice object will be instantiated and called as such:
     * StockPrice* obj = new StockPrice();
     * obj->update(timestamp,price);
     * int param_2 = obj->current();
     * int param_3 = obj->maximum();
     * int param_4 = obj->minimum();
     */