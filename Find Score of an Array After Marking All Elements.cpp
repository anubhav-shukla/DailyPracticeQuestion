class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long scores = 0;

        // Pair each value with its index and sort
        vector<pair<int, int>> sortedNums;
        for (int i = 0; i < n; ++i) {
            sortedNums.push_back({nums[i], i});
        }
        sort(sortedNums.begin(), sortedNums.end()); // O(n log n)

        // Track marked indices
        vector<bool> marked(n, false);

        // Process the sorted list
        for (auto& [val, index] : sortedNums) {
            if (!marked[index]) {
                scores += val; // Add to score

                // Mark the current index and adjacent indices as invalid
                if (index - 1 >= 0) marked[index - 1] = true;
                if (index + 1 < n) marked[index + 1] = true;
                marked[index] = true;
            }
        }

        return scores;
    }
};