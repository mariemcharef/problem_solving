#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class ExamRoom {
    private:
        int n;
        set<int> seated;
        
    public:
        ExamRoom(int n) {
            this->n = n;
        } 
        int seat() {
            if (seated.empty()) {
                seated.insert(0);
                return 0;
            }
            
            int max_dist = *seated.begin(); 
            int pos = 0;
            int prev = *seated.begin();
            
            for (auto it = next(seated.begin()); it != seated.end(); ++it) {
                int curr = *it;
                int dist = (curr - prev) / 2;
                if (dist > max_dist) {
                    max_dist = dist;
                    pos = prev + dist;
                }
                prev = curr;
            }
            
            int last_dist = (n - 1) - prev;
            if (last_dist > max_dist) {
                pos = n - 1;
            }
            
            seated.insert(pos);
            return pos;
        }
        
        void leave(int p) {
            seated.erase(p);
        }
    };