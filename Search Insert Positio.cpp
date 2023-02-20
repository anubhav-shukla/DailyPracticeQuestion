class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0,ans=0;
        int n=nums.size()-1;
        if(nums[n]<target){
            return n+1;
        }
        while(s<=n){
            int mid=s+(n-s)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            else if(nums[mid]>target){
                n=mid-1;
            }
            else{
                s=mid+1;
                ans=mid+1;
            }
        }
        return ans;
    }
};