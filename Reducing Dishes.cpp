class Solution {
public:
    int f(int t, int i, vector<int>&satisfaction,vector<vector<int>>&dp){
        int n=satisfaction.size();

        if(i>=n){
            return 0;
        }
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        int take=(t+1)*satisfaction[i]+f(t+1,i+1,satisfaction,dp);
        int nottake=f(t,i+1,satisfaction,dp);
        return dp[i][t]=max(take,nottake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return f(0,0,satisfaction,dp);
    }
};