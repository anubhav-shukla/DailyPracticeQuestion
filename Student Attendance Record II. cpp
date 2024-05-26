class Solution {
    private static final int MOD = 1000000007;

    public int checkRecord(int n) {
        int[][] dp = new int[3][4];
        int[][] prevDp = new int[3][4];

        for (int ac = 0; ac <= 1; ac++) {
            for (int clc = 0; clc <= 2; clc++) {
                prevDp[ac][clc] = 1;
            }
        }

        for (int day = 1; day <= n; day++) {
            for (int ac = 0; ac <= 1; ac++) {
                for (int clc = 0; clc <= 2; clc++) {
                    dp[ac][clc] = prevDp[ac][0] % MOD;
                    dp[ac][clc] = (dp[ac][clc] + prevDp[ac + 1][0]) % MOD;
                    dp[ac][clc] = (dp[ac][clc] + prevDp[ac][clc + 1]) % MOD;
                }
            }
            for (int ac = 0; ac <= 1; ac++) {
                for (int clc = 0; clc <= 2; clc++) {
                    prevDp[ac][clc] = dp[ac][clc];
                }
            }

        }

        return dp[0][0];
    }
}