class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int k=1;
        for(int i=n;i<2*n;i++)
        {
            int temp=nums[i];
            nums.erase(nums.begin()+i);
            nums.insert(nums.begin() + k, temp);
            k+=2;
  
        }
        return nums;
    }
};