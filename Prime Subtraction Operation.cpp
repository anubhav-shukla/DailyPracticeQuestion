class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        //prime no generation
        vector<int>primeNums;
        for(int i = 2; i < 1001; i++) {
            int tmp = 0;
            for(int j = 1; j <= i; j++) {
                if(i % j == 0) {
                    tmp++;
                }
            }
            if(tmp == 2) {
                primeNums.push_back(i);
            }
        }

        int n = nums.size();
        vector<int>ans;
        ans.push_back(0);
        for(int i=0; i<n; i++) {
            int target = nums[i] - ans[i];
            int foundIndex = (lower_bound(primeNums.begin(), primeNums.end(), target) - primeNums.begin()) -1;
            if(foundIndex >= 0){
                ans.push_back(nums[i] - primeNums[foundIndex]);
            }
            else ans.push_back(nums[i]);
            // else return false;
        }

        // for(auto i:ans) cout << i << " " ;
        for(int i=1; i<ans.size(); i++){
            if(ans[i] <= ans[i-1]) return false;
        }

        return true;
    }
};