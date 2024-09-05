class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int avg = n + m;
        // Known+missing..
        int totSum = mean * (avg);

        // lets find the known numbers on dice..
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += rolls[i];
        }
        // Find the missing one..
        int missing = totSum - sum;
        
        if (missing < n || missing > 6 * n) {
            return {};
        }

        // Calculate the base value and the remainder.
        int baseValue = missing / n;
        int remainder = missing % n;
        vector<int> result(n, baseValue);
        for (int i = 0; i < remainder; i++) {
            result[i]++;
        }

        return result;
    }
};