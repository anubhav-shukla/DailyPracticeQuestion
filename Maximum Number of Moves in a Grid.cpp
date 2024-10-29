class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        
        int M=grid.size(),N=grid[0].size(); //storing the number of rows as M and columns as N
        
        vector<vector<int>>dp(M,vector<int>(N,0)); // creating a 2D vectpr tp track the changes of i and j as dynamic programming tabulation
        
        int maxMoves=0; // we store the max number of moves
        
        for(int i=0;i<M;i++) // we initialize the first col as 1 indicating possible routes ways
            dp[i][0]=1;
        
        for(int j=1;j<N;j++) // we travel column wise
        {
            for(int i=0;i<M;i++) // we iterate the rows for manipulation
            {
                if(dp[i][j-1]>0 && grid[i][j]>grid[i][j-1]) // checking if the standing at (i,j) is (i,j-1) was smaller and dp(i,j-1) is smaller or not if so we store the max of dp(i,j-1) and dp(i,j-1)+1
                {
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
                }
                
                if(i-1 >=0 && dp[i-1][j-1]>0 && grid[i][j]>grid[i-1][j-1])// checking if the standing at (i,j) is (i-1,j-1) was smaller and dp(i-1,j-1) is smaller or not if so we store the max of dp(i-1,j-1) and dp(i-1,j-1)+1 and also check i-1>=0 or not
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
                
                if(i+1<M && grid[i][j]>grid[i+1][j-1] && dp[i+1][j-1]>0)// checking if the standing at (i,j) is (i+1,j-1) was smaller and dp(i+1,j-1) is smaller or not if so we store the max of dp(i+1,j-1) and dp(i+1,j-1)+1 and also check i+1<M or not
                {
                    dp[i][j]=max(dp[i][j],dp[i+1][j-1]+1);
                }
            
                maxMoves=max(maxMoves,dp[i][j]-1); // the maxMoves stores the max all dp(i,j) and subtracts 1 from them to balance since we marked col 1 with 1
            
            }
            
            
        }
        
        //return the max number of Moves
        return maxMoves;
        
    }
};