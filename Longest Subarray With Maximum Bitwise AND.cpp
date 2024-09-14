class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = nums[0];
        for (int x : nums) {
            max_val = max(max_val, x);
        }
    
        int max_length = 1;
        int current_length = 0;
    
        for (int x : nums) {
            if (x == max_val) {
                current_length++;
            }
            else {
                max_length = max(max_length, current_length);
                current_length = 0;
            }
        }   

        return max(max_length, current_length);
    }
};