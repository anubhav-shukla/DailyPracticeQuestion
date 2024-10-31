class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        int n = robot.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factories;

        for (int i = 0; i < factory.size(); i++) {
            for (int j = 0; j < factory[i][1]; j++) {
                factories.push_back(factory[i][0]);
            }
        }
        int m = factories.size();

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i < m + 1 && i < n; i++) {
            dp[i][i + 1] = LLONG_MAX;
        }
        dp[0][0] = 0;

        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1 && j <= i; j++) {
                // cout << dp[i - 1][j] << "\n";
                // cout << dp[i - 1][j - 1] << "\n";
                // cout << "\n";
                if (dp[i - 1][j] < dp[i - 1][j - 1] + abs(robot[j - 1] - factories[i - 1])) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] =dp[i - 1][j - 1] + abs(robot[j - 1] - factories[i - 1]);
                }
                
            }
        }





        return dp.back().back();;
    }
};