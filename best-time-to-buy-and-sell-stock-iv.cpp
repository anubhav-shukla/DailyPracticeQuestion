#include <bits/stdc++.h>
using namespace std;
 
  int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int dp[n + 1][k + 1][2];
        for(int idx = 0; idx <= n; ++idx) {
            for(int k_ = 0; k_ <= k; ++k_) {
                for(int taken = 0; taken < 2; ++taken) {
                    if(k_ == 0 || idx == n) dp[idx][k_][taken] = 0;
                }
            }
        }
        for(int idx = n - 1; idx >= 0; -- idx) {
            for(int k_ = k; k_ > 0; --k_) {
                for(int taken = 1; taken >= 0; --taken) {
                    if(taken)   dp[idx][k_][taken] = max(prices[idx] + dp[idx + 1][k_ - 1][0], dp[idx + 1][k_][1]);
                    else    dp[idx][k_][taken] = max(-prices[idx] + dp[idx + 1][k_][1], dp[idx + 1][k_][0]);
                }
            }
        }
        return dp[0][k][0];
    }


    int main(){
       int  k = 2;
       vector<int> prices = {2,4,1};
       cout<<maxProfit(k,prices);
    }