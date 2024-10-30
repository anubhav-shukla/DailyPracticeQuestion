class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> DP(n), LIS;
        for(int i = 0; i < n; i++) {
            if(LIS.empty() || nums[i] > LIS.back()) {
                LIS.push_back(nums[i]);
                DP[i] = LIS.size();
            } else {
                int index = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin(); 
                LIS[index] = nums[i];
                DP[i] = index + 1;
            }
        }
        LIS.resize(0);
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(LIS.empty() || nums[i] > LIS.back()) {
                LIS.push_back(nums[i]);
                if(DP[i] != 1 && LIS.size() != 1)
                    ans = max(ans, DP[i] + (int)LIS.size() - 1);
            } else {
                int index = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin(); 
                LIS[index] = nums[i];
                if(DP[i] != 1 && index != 0) 
                    ans = max(ans, DP[i] + index);
            }
        }
        return n - ans;
    }
};