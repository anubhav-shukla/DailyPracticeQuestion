class Solution {
public:
    std::vector<int> preProcessing(std::vector<int>& nums) {
        int size = nums.size();
        // 0 -> Odd
        // 1 -> Even
        std::vector<int> result(size, 0);
        for (int i = 1; i < size; i++) {
            if (nums[i] % 2 == 0 && nums[i - 1] % 2 != 0 ||
                nums[i] % 2 != 0 && nums[i - 1] % 2 == 0) {
                result[i] = result[i - 1];
            } else {
                result[i] = 1 + result[i - 1]; // We found one difference in the character 
            }
        }
        return result;
    }
    bool compute(vector<int>& nums, int start, int end) {
        if (nums[start] == nums[end]) {
            return true;
        }
        return false;
    }
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        std::vector<bool> result;
        std::vector<int> preProcessed = preProcessing(nums);

        for (const auto& query : queries) {
            bool value = compute(preProcessed, query[0], query[1]);
            result.push_back(value);
        }
        return result;
    }
};

