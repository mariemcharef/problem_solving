
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class MyCalendar {
    public:
        set<long long > st;
        map<long long,long long> mp;
        MyCalendar() {
            
        }
        
        bool book(int s, int e) {
            if (st.empty()) {
            st.insert(s);
            mp[s] = e;
            return true;
            }
            auto it =st.lower_bound(s);
             if(it==st.begin()){
                int ls=*it;
                int le=mp[ls];
                if(ls>=e){
                   st.insert(s);
                    mp[s]=e;
                    return true;
                }
                return false;
            }
            
            if(it==st.end() ){
                it--;
                int ls=*it;
                int le=mp[ls];
                if(le<=s){
                    st.insert(s);
                    mp[s]=e;
                    return true;
                }
                return false;
            }
           
            int s2=*it;
            int e2=mp[s2];
            it--;
            int s1=*it;
            int e1=mp[s1];
            if(s>=e1 && e<=s2){
                st.insert(s);
                mp[s]=e;
                return true;
            }
            return false;
            
        }
    };
    
    