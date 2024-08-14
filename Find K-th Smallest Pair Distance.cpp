class Solution {
public:

    int cntpairs(int mid,vector<int>& nums){
        int l=0,r=1;
        int cnt=0;
        int n=nums.size();
        while(r<n){
            // int diff=abs(nums[r]-nums[l]);
            while(abs(nums[r]-nums[l])>mid){
                l++;
            }
            cnt+=r-l;
            r++;
        }

        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // ans lies in (0....max_ele)
        int l=0,r=nums[nums.size()-1]-nums[0];
        while(l<r){
            int mid=l+(r-l)/2;
            // count pairs having smaller or equal dist to mid
            if(cntpairs(mid,nums)>=k){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};