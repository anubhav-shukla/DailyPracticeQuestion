#include<bits/stdc++.h>
using namespace std;
 int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int INF = 1000000;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(target + 1, vector<int>(n, INF)));
            
        for (int c = 1; c <= n; c++)
            if (houses[0] == c)
                dp[0][1][c - 1] = 0;
            else if (!houses[0])
                dp[0][1][c - 1] = cost[0][c - 1];
        
        for (int i = 1; i < m; i++)
            for (int k = 1; k <= min(target, i + 1); k++)
                for (int c = 1; c <= n; c++) {
                    if (houses[i] && c != houses[i]) continue;
                    int same_neighbor = dp[i - 1][k][c - 1];
                    int diff_neighbor = INF;
                    for (int c_ = 1; c_ <= n; c_++)
                        if (c_ != c)
                            diff_neighbor = min(diff_neighbor, dp[i - 1][k - 1][c_ - 1]);
                    int paint_cost = cost[i][c - 1] * int(!houses[i]);
                    dp[i][k][c - 1] = min(same_neighbor, diff_neighbor) + paint_cost;
                }
        int res = *min_element(dp.back().back().begin(), dp.back().back().end());
        return (res < INF) ? res : -1;            
    }

    int main(){
        int m = 5; 
        int n = 2; 
        vector<int> v {0,0,0,0,0};
        vector<vector<int>> vect{
                   {1,10},{10,1},{10,1},{1,10},{5,1}
        };
       
        
        int target = 3;
        cout<<minCost(v,vect,m,n,target);

    }


