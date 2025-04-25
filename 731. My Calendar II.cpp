#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class MyCalendarTwo {
    vector<pair<int,int>> l1;
    vector<pair<int,int>> l2;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        
        for (auto &event : l2) {
             if (!(event.second <= startTime || event.first >= endTime)) {
                return false;
            }
        }
        for(int i=0;i<l1.size();i++){
            int mn=max(l1[i].first,startTime);
            int mx=min(l1[i].second,endTime);

            if(mn<mx){
                l2.push_back(make_pair(mn,mx));
            }

        }
        l1.push_back(make_pair(startTime,endTime));
        return true;
    }
};

