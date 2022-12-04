 int minimumAverageDifference(vector<int>& nums) {
        
        long long int totalSum=0, currSum=0, n=nums.size();
        long long int index=-1, miniAvg=INT_MAX, avg;
        for(auto &ele : nums){
            totalSum += ele;
        }
        for(int i=0;i<n-1;i++){
            currSum += nums[i];
            avg = (currSum/(i+1)) - ((totalSum-currSum)/(n-i-1));
            avg = abs(avg);
            if( miniAvg > avg ) miniAvg=avg, index = i;
        }
        if( miniAvg > (totalSum/n) ) return n-1;
        return index;
    }