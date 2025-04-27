#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    public:
        int maximumRobots(vector<int>& charge, vector<int>& costs, long long budget) {
            int n = charge.size();
            int i = 0, ans = 0;
            long long costSum = 0;
            multiset<int> mxC;
            for (int j = 0; j < n; ++j) {
                costSum += costs[j];
                mxC.insert(charge[j]);
                while (!mxC.empty() && *mxC.rbegin() + (j - i + 1) * costSum > budget) {
                    costSum -= costs[i];
                    mxC.erase(mxC.find(charge[i]));
                    i++;
                }
                ans = max(ans, j - i + 1);
            }
    
            return ans;
        }
    };
    