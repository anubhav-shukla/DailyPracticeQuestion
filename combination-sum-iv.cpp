#include <bits/stdc++.h>
using namespace std;




int combinationSum4(vector<int>& nums, int target) {
	sort(begin(nums), end(nums));
    vector<int> dp(target + 1); dp[0] = 1;
	for (int curTarget = 1; curTarget <= target; curTarget++) 
        for (auto& num : nums) 
            if (num <= curTarget)  dp[curTarget] += dp[curTarget - num];
            else break;
    return dp[target];
}


int main(){
    vector<int> nums = {1,2,3}; 
    int target=4;
   cout<<combinationSum4(nums,target);
}