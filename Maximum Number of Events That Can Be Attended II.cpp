class Solution {
public:
    int solveDp(vector<vector<int>>& e,int k,int index,vector<vector<int>>&dp){

        //base case
        if(index>=e.size()|| k<=0){
            return 0;
        }
        if(dp[index][k]!=-1){
            return dp[index][k];
        }
        int i;
        for( i=index+1;i<e.size();i++){
            if(e[i][0]>e[index][1])
             break;
        }
        int include=e[index][2]+solveDp(e,k-1,i,dp);
        int exclude= solveDp(e,k,index+1,dp);
        return dp[index][k]=max(include,exclude);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        //sort events by startTime
        sort(events.begin(),events.end());

        int n=events.size();

        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));

        return solveDp(events,k,0,dp);

    }
};