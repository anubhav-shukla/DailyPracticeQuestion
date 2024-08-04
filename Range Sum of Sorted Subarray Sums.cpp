static auto stdio = ios::sync_with_stdio(false);
static auto cinTie = cin.tie(nullptr);
static auto coutTie = cout.tie(nullptr);

class Solution {
public:
    int minSum, maxSum;
    const int MOD = 1e9 + 7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // Calculate minimum element and total sum of the array
        minSum = *min_element(nums.begin(), nums.end());
        maxSum = accumulate(nums.begin(), nums.end(), 0);

        // Calculate the sum of subarrays in the given range
        return (calculateSum(nums, right) - calculateSum(nums, left - 1) + MOD) % MOD;
    }

private:
    pair<int, int> slidingWindowSum(vector<int>& nums, int target) {
        int subarrayCount = 0;
        int totalSum = 0;
        int windowSum = 0;
        int currentSum = 0;
        
        for (int j = 0, i = 0; j < nums.size(); ++j) {
            currentSum += nums[j];
            windowSum += (1LL * nums[j] * (j - i + 1)) % MOD;
            if (windowSum >= MOD) windowSum -= MOD;

            while (currentSum > target) {
                windowSum -= currentSum;
                currentSum -= nums[i++];
                if (windowSum < 0) windowSum += MOD;
                if (currentSum < 0) currentSum += MOD;
            }
            
            subarrayCount += (j - i + 1);
            totalSum += windowSum;
            if (totalSum >= MOD) totalSum -= MOD;
        }
        return {subarrayCount, totalSum};
    }

    int calculateSum(vector<int>& nums, int target) {
        int res = -1, left = minSum, right = maxSum;

        // Binary search to find the threshold value
        while (left <= right) {
            int mid = (left + right) / 2;
            if (slidingWindowSum(nums, mid).first >= target)
                res = mid, right = mid - 1;
            else left = mid + 1;
        }

        // Calculate the sum of subarrays up to the threshold
        auto [count, sum] = slidingWindowSum(nums, res);
        return (sum - (1LL * res * (count - target)) % MOD + MOD) % MOD;
    }
};