class Solution {
public:
    int getSortedBigestElement(vector<int>& nums, int start, int end) {
        for (int i = start; i < end; i++) {
            if ((nums[i] + 1 != nums[i + 1]))
                return -1;
        }
        return nums[end];
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int l = 0;
        int consec_cnt = 1;

        for (int r = 0; r < n; r++) {
            // Check consecutiveness
            if (r > 0 && nums[r] - nums[r - 1] == 1) {
                consec_cnt++;
            }

            // When window size equals k
            if (r - l + 1 == k) {
                if (consec_cnt == k) {
                    ans.push_back(nums[r]);
                } else {
                    ans.push_back(-1);
                }

                // Adjust the counter for sliding the window
                if (r + 1 < n && nums[l + 1] - nums[l] == 1) {
                    consec_cnt--;
                }
                l++;
            }
        }

        return ans;
    }
};