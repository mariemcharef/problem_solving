#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Seg{
        int l, r, c;
    };

    map<int , Seg> mp;// key: left index, value: segment
    multiset<int> lengths; // store lengths of segments

    void add_Segment(int l, int r, int c) {
        mp[l] = {l, r, c};
        lengths.insert(r - l + 1);
    }
    void remove_Segment(int l) {
        auto it = mp.find(l);
        if (it != mp.end()){
            lengths.erase(lengths.find(it->second.r - it->second.l + 1));
            mp.erase(it);
        }
    }

    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        int n = s.size();
        mp.clear();
        lengths.clear();

        for (int l = 0; l < n;) {
            int r = l;
            while(r<n && s[r] == s[l]) r++;
            add_Segment(l, r - 1, s[l] - 'a');
            l=r;
        }

        int k=qi.size();
        vector<int> ans(k);

        for (int q = 0; q < qi.size(); q++) {
            int index = qi[q];
            int new_c = qc[q] - 'a';

            auto it = prev(mp.upper_bound(index));
            Seg  curr = it->second;

            if(curr.c == new_c){
                ans[q] = *lengths.rbegin();
                continue;
            }

            remove_Segment(curr.l);
            int r = curr.r;
            int l = curr.l;

            if(l < index){
                add_Segment(l, index - 1, curr.c);
            }

            add_Segment(index, index, new_c);

            if(index < r){
                add_Segment(index + 1, r, curr.c);
            }
            if(l< index && index < r){
                ans[q] = *lengths.rbegin();
                continue;
            }

            //merge with left segment
            auto it2 = mp.find(index);
            if(it2 != mp.begin()){
                auto itl = prev(it2);
                if(itl->second.c == it2->second.c){
                    int new_l = itl->second.l;
                    int new_r = it2->second.r;
                    int c = it2->second.c;
                    remove_Segment(itl->second.l);
                    remove_Segment(it2->second.l);
                    add_Segment(new_l, new_r, c);
                    it2 = mp.find(new_l);
                }
            }

            auto itr = next(it2);
            if(itr != mp.end() && itr->second.c == it2->second.c){
                int new_l = it2->second.l;
                int new_r = itr->second.r;
                int c = it2->second.c;
                remove_Segment(it2->second.l);
                remove_Segment(itr->second.l);
                add_Segment(new_l, new_r, c);
            }
            

            ans[q] = *lengths.rbegin();

            
        }

        return ans;
    }
};