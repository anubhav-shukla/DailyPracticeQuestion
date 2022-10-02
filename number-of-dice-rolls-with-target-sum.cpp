
 #include <bits/stdc++.h>
using namespace std;


int numRollsToTarget(int n, int k, int target) {
       vector<vector<int>> dp(n+1,vector<int>(target+1,0));
       dp[0][0] = 1;
       for (int i = 0; i<n; i++)
       {
           for(int j = i;  j<=target; j++)
           if (dp[i][j] != 0)
           {
                for(int l = 1; l<=k && j+l<=target; l++)
                dp[i+1][j+l] = (dp[i+1][j+l]+ dp[i][j])%1000000007;
           }
       }
       return dp[n][target];
   }

   int main(){
  int  n = 1, k = 6, target = 3;
            cout<<numRollsToTarget(n,k,target);
   }