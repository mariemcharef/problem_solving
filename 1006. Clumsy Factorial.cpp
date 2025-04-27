#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    public:
        int clumsy(int n) {
            stack<int> stk;
            stk.push(n);
            n--;
            int op = 0; 
            while (n > 0) {
                if (op == 0) {
                    stk.top() *= n;
                } else if (op == 1) {
                    stk.top() /= n;
                } else if (op == 2) {
                    stk.push(n);
                } else { 
                    stk.push(-n);
                }
                n--;
                op = (op + 1) % 4;
            }
    
            int result = 0;
            while (!stk.empty()) {
                result += stk.top();
                stk.pop();
            }
            return result;
        }
    };