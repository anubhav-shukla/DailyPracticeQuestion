class Solution {
public:
void update(vector<int>&vec,int num,int op )
{
    for(int i=0;i<32;i++)
    {
        if(num & (1<<i) )
        vec[i]+=op;
    }
}
int dtb(vector<int>&vec)
{
    int num=0;

    for(int i=0;i<32;i++)
    {
        if(vec[i]>0)
        {
            num |=(1<<i);
        }
    }
    return num;
}
    int minimumSubarrayLength(vector<int>& nums, int k) {
     
int n=nums.size();
int i=0;
int j=0;
int ans=INT_MAX;
vector<int>vec(32,0);

while(j<n)
{
    // aadd count of all bits of nums[i] in vec
    update(vec,nums[j],1);
    while(i<=j && dtb(vec)>=k)
    {
        ans=min(ans,j-i+1);
        // remove count of nums[i];
        update(vec,nums[i],-1);
        i++;
    }
    j++;
}
return ans == INT_MAX? -1: ans;
    }
};