class Solution {
public:
    long long f(int i,int size,vector<vector<int>>&questions,vector<long long>&dp){
       
        if(i>=size){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        long long take=0,nontake=0;
         take=questions[i][0]+f(i+questions[i][1]+1,size,questions,dp);
         nontake=f(i+1,size,questions,dp);
        return dp[i]=max(take,nontake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size(),-1);
        return f(0,questions.size(),questions,dp);
    }
};