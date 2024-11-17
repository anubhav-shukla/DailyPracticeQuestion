class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
       long long n=nums.size(),mx=1e11,sum=0;
       deque<pair<long long ,long long>>dq;
       dq.push_back({0,-1});
     for(long long i=0;i<n;i++){
           sum+=(long long)nums[i];
         while(!dq.empty() and sum<dq.back().first) dq.pop_back();

         while(!dq.empty() and sum-dq.front().first>=k){
             mx=min(mx,(long long)(i-dq.front().second));
             dq.pop_front();
         }
         dq.push_back({sum,i});
     }
     if(mx==1e11){ return -1; }
     return mx;  
    }
};