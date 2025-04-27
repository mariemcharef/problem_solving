#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class TweetCounts {
    public:
        map<string,multiset<int>> mp;
        TweetCounts() {
            
        }
        
        void recordTweet(string tweetName, int time) {
            mp[tweetName].insert(time);
            
        }
        
        vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
            vector<int>ans;
             
            int delta = 0;
            if (freq == "minute") {
                delta = 60;
            } else if (freq == "hour") {
                delta = 3600;
            } else if (freq == "day") {
                delta = 86400;
            }
            for (int i = startTime; i <= endTime; i += delta) {
                int interval_start = i;
                int interval_end = min(i + delta - 1, endTime);
                
                auto it_start = mp[tweetName].lower_bound(interval_start);
                auto it_end = mp[tweetName].upper_bound(interval_end);
    
                int dis=distance(it_start, it_end);
                ans.push_back(dis);
                
               
            }
    
            return ans;
        }
    };
    
    /**
     * Your TweetCounts object will be instantiated and called as such:
     * TweetCounts* obj = new TweetCounts();
     * obj->recordTweet(tweetName,time);
     * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
     */