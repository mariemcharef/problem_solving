#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SmallestInfiniteSet {
    set<int> s;
    int smallest ;
    
public:
    SmallestInfiniteSet() {
        smallest=1;
    }
    
    int popSmallest() {
       if(!s.empty()){
        int ans=*s.begin();
        s.erase(s.begin());
        if(smallest>ans){
            return(ans);
        }
       }
       return smallest++;
    }
    void addBack(int num) {
        if(num<smallest)s.insert(num);
    }
};

