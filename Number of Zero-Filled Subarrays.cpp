class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i]) continue;
            int j = i;
            while (j < n && !nums[j]) ++j;
            res += 1LL * (j - i) * (j - i + 1) / 2;
            i = j - 1;
        }
        return res;
    }
};