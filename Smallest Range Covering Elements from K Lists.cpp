class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int totalsum=0;
        for(auto it:nums)
        totalsum+=it.size();
        int groups=nums.size();
        int index=0;
        vector<pair<int,int>>ar(totalsum);
        for(int i=0;i<groups;i++)
        {
            for(int x:nums[i])
            ar[index++]={x,i};
        }
        sort(ar.begin(),ar.end());
        vector<int>range={-100000,100000};
        unordered_map<int,int>mp;
        int start=0;
        for(int end=0;end<totalsum;end++)
        {
            int currvalue=ar[end].first;
            int currgroup=ar[end].second;
            mp[currgroup]++;
            while(mp.size()==groups)
            {
                int value=ar[start].first;
                int group=ar[start].second;
                int crange=currvalue-value;
                int bestrange=range[1]-range[0];
                if(crange<bestrange || crange==bestrange && value<range[0])
                {
                    range[0]=value;
                    range[1]=currvalue;
                }
                if(--mp[group]==0)
                mp.erase(group);
                start++;
            }
    
        }
        return range;
    }
};