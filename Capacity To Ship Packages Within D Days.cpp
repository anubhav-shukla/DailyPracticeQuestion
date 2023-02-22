class Solution {
public:
    bool isValid(vector<int>& weights,int n,int days,int mx)
    {
        int st=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=weights[i];
            if(sum>mx)
            {
                st++;
                sum=weights[i];
            }
            if(st>days)
                return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) 
    {
        int sum=0;
        for(int i=0;i<weights.size();i++)
            sum+=weights[i];
        int s=weights[0];
        for(int i=0;i<weights.size();i++)
        {
            s=max(s,weights[i]);
        }
        int e=sum;
        int res=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isValid(weights,weights.size(),days,mid))
            {
                res=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return res;
    }
};