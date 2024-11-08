class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        vector<int> ans(nums.size(), 0);

        int curr = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            curr ^= nums[i];
            ans[nums.size() - 1 - i] = curr ^ ((1 << maximumBit) - 1);
        }

        return ans;    
    }
};