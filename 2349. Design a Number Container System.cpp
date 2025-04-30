#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


class NumberContainers {
    public:
        map<long long,long long>m1;
        map<long long,set<long long>> m2;
        NumberContainers() {
        }
        void change(int index, int number) {
            if(m1[index]){
                m2[m1[index]].erase(index);
            }
            m1[index]=number;
            m2[number].insert(index);
        }
        
        int find(int number) {
            if(m2[number].empty()){
                return -1;
            }
            return *m2[number].begin();
        }
    };
    
    