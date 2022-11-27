int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long,int>> ind_diff(n);  // Store for every index number of sequence ending at i with differnece d  (ind_diff[i][diff])
        int ans = 0;  // Store ans
        for(int i=0;i<n;i++){
            int cur = 0; // Store no of valid sequence ending at i index 
            for(int j=0;j<i;j++){
                long long diff = (long)nums[i]-nums[j];  // diff b/w both indices
                cur = cur + ind_diff[j][diff];    // no. of valid sequence ending at i index with difference diff
                ind_diff[i][diff]+=(ind_diff[j][diff]+1);  // add current sequence (nums[j] ,nums[i]) + previous sequence ending at j equal to total no of sequence ending at i with difference diff
            }
            ans+=cur; // Finally add cur to ans
        }
        return ans;
    }