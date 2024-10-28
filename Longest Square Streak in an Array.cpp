class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
    
        long long n = nums.size();
        long long ans = 0;

        unordered_set<long long>st(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++)
        {
            long long val = nums[i];
            long long cnt = 1;

            if(val * val > 1e5)
            continue;
            
            while(st.find(val*val) != st.end())
            {
                cnt++;
                if(val * val > 1e5)
                break;
                
                val = val*val;
            }
            ans = max(ans, cnt);
        }

        if(ans < 2)
        return -1;

        return ans;
    }
};
