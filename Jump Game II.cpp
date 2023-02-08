class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int count=0,start=0,end=0;

        if(n==1)
        return 0;

        for(int i=0;i<n-1;i++)
        {
            start=max(start,nums[i]+i);
            if(i==end)
            {
                count++;
                end=start;
            }
        }
        return count;
    }
};