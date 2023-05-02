class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        int ans;
        for(auto i:nums){
            if(i==0) { count = 0; break; }
            else if(i < 0) { count++; }
            else { 
                if(i == nums[nums.size()-1] && count == 0){
                    count = 51;
                }
            }
        }   
        if(count == 51)
        ans = 1;
        else if(count == 0) 
        ans = 0;
        else if(count > 0 && count%2 == 0) 
        ans = 1;
        else if(count > 0 && count%2 != 0) 
        ans = -1;   

        return ans;          
    }
};