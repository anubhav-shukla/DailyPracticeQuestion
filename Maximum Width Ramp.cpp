class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        int maxValue = 0;
        for (int i=n-1; i>=0; i--) {
            maxValue = max(maxValue, nums[i]);
            arr[i] = maxValue;
        }
        int l = 0, r = 1;
        int temp = 0;
        int res = 0;
        while (r < n) {
            if (nums[l] <= arr[r]) {
                temp = r - l;
                r ++;
            } else {
                l ++;
                temp = r - l;
            }
            res = max(res, temp);
        }
        return res;
    }
};