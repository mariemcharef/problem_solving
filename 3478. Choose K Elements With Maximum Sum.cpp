class Solution {
    public:
        vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {   
            int n = nums1.size();
            vector<array<int,3>> elements(n);
            for(int i=0;i<n;i++){
                elements[i]={nums1[i],nums2[i],i};
            }
            sort(elements.begin(),elements.end());
            vector<long long> ans(n);
            priority_queue<int,vector<int>,greater<int>> h;
            long long sum=0;
            for(int i=0;i<n;i++){
                if (i>0 && elements[i-1][0]==elements[i][0]){
                    ans[elements[i][2]]=ans[elements[i-1][2]];
                }else{
                    ans[elements[i][2]]=sum;
                }
                sum+=elements[i][1];
                h.push(elements[i][1]);
                if(h.size()>k){
                    sum-=h.top();
                    h.pop();
                }
            }
        return ans;
    }
        
    };