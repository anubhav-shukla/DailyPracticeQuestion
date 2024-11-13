class Solution {
public:
    int binarySearch(std::vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return right + 1;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long output = 0;
        for (int index = 0; index < nums.size(); ++index) {
            int left = binarySearch(nums, index + 1, nums.size() - 1, lower - nums[index]);
            int right = binarySearch(nums, index+ 1, nums.size() - 1, upper - nums[index] + 1);
            output += right - left;
        }
        return output;
    }
};