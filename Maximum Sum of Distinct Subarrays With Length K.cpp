class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long mx = 0,sum=0;
        int n = nums.size();
        unordered_set<int>st;
        int i=0,j=0;
        while(j<n)
        {
            //shrink 
            int duplicate = nums[j];
            if(st.find(nums[j]) != st.end())
            {
                while(st.find(duplicate)!=st.end())
                {
                    sum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
            sum += nums[j];
            st.insert(nums[j]);
            if(j-i+1 == k) 
            {
                mx = max(mx,sum);
                //shrink
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return mx;
    }
};