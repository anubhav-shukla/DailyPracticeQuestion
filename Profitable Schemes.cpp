class Solution {
public:
    int dp[101][101][101];
    int mod=1e9+7;
    int solve(int idx,int p,int n, int minProfit, vector<int>& group, vector<int>& profit){
        if(idx<0){
            if(p>=minProfit)
                return 1;
            return 0;
        }
        if(dp[idx][p][n]!=-1)
            return dp[idx][p][n];
        int notPick=solve(idx-1,p,n,minProfit,group,profit);  // Choose NOT to be a part
        int pick=0;
        if(n>=group[idx]) // Choose to be a part thus reduce Group and add Profit
            pick=solve(idx-1,min(p+profit[idx],minProfit),n-group[idx],minProfit,group,profit); // Take min() to fit the Array Max Size
        
        return dp[idx][p][n]=(pick+notPick)%mod;
        
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        int size=group.size();
        return solve(size-1,0,n,minProfit,group,profit);
    }
};