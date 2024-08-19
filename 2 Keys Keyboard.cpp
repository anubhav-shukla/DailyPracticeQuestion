class Solution {
public:
    bool isPrime(int N)
    {
        if (N <= 1) {
            return false;
        }
        if (N <= 3) {
            return true;
        }
        if (N % 2 == 0 || N % 3 == 0) {
            return false;
        }
        for (int i = 5; i * i <= N; i += 6) {
            if (N % i == 0 || N % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    pair<int,int> getfactors(int n)
    {
        for (int i = sqrt(n); i >= 1; i--) {
            if (n % i == 0) {
                if (n / i == i)
                    return {i,i};
                else 
                    return {i, n/i};
            }
        }
        return {};
    }

    int solve(int n, vector<int>&dp){
        if(n == 1){
            return 0;
        }
        if(dp[n] != -1) return dp[n];
        if(isPrime(n)){
            dp[n] = n;
        }
        else if(n%2 == 0){
            dp[n] = solve(n/2, dp) + 2;
        }
        else {
            pair<int,int> factors = getfactors(n);
            dp[n] = solve(factors.first, dp) + solve(factors.second, dp);
        }
        return dp[n];
    }

    int minSteps(int n) {
        vector<int> dp(n+1, -1);
        // if(isPrime(n)) return n;
        dp[1] = 0;
        solve(n, dp);
        return dp[n];
    }
};