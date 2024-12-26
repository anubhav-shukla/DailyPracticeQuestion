class Solution {
    int maxi, n;
    int solve(vector<int>& nums, vector<vector<int>>& dp, int idx, int currSum, int target) {
        if (idx >= n) {
            return currSum == target;
        }
        if (dp[idx][currSum + maxi] != -1) {
            return dp[idx][currSum + maxi];
        }
        int neg = solve(nums, dp, idx + 1, currSum - nums[idx], target);
        int pos = solve(nums, dp, idx + 1, currSum + nums[idx], target);
        return dp[idx][currSum + maxi] = neg + pos;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        maxi = accumulate(nums.begin(), nums.end(), 0);
        n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2 * maxi + 1, -1));
        return solve(nums, dp, 0, 0, target);
    }
};