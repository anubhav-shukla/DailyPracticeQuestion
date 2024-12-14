class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long numOfCont=1;
        int maxIndex=0,minIndex=0,intialIndex=0;
        for(int i=1;i<n;i++){
            if((abs(nums[minIndex]-nums[i])<3 && abs(nums[maxIndex]-nums[i])<3)){
                if(nums[i]>nums[maxIndex]){
                    maxIndex=i;
                }
                else if(nums[i]<nums[minIndex]){
                    minIndex=i;
                }
                numOfCont+=i-intialIndex+1;
            }
            else{
                int j=i-1;
                minIndex=maxIndex=i;
                while(abs(nums[i]-nums[j])<3){
                    if(nums[j]>nums[maxIndex]){
                        maxIndex=j;
                    }
                    else if(nums[j]<nums[minIndex]){
                        minIndex=j;
                    }
                    j--;
                }
                intialIndex=j+1;
                 numOfCont+=i-intialIndex+1;
            }
        }
        return numOfCont;
    }
};