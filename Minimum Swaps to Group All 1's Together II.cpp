class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        vector<int> pf(2*n,0);
        for(int i=0;i<2*n;i++)
            pf[i]+=1-nums[i%n]+(i>0?pf[i-1]:0);
        
        int cnt=n-pf.back()/2;
        for(int i=0;i<n;i++)
            ans=min(ans,pf[i+cnt]-pf[i]);
        
        return ans;
    }
};