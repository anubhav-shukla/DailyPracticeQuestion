class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap to store elements in the format {value, list index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Step 1: Insert all elements into the min-heap along with their respective list index
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                minHeap.push({nums[i][j], i});  // {value, list index}
            }
        }

        // Step 2: Extract all elements into a window (a vector of pairs)
        vector<pair<int, int>> window;
        while (!minHeap.empty()) {
            window.push_back(minHeap.top());
            minHeap.pop();
        }

        // Sliding window variables
        int i = 0, j = 0;
        int minval = -100000, maxval = 100000;  // Initialize with large default range
        unordered_map<int, int> freqMap;     // To track the frequency of lists covered in the current window

        // Step 3: Sliding window to find the smallest range
        while (j < window.size()) {
            auto [val2, ind2] = window[j];
            freqMap[ind2]++;  // Increment the frequency of the current element's list index

            // When we have elements from all lists, try to shrink the window
            while (freqMap.size() == nums.size()) {
                auto [val1, ind1] = window[i];  // Get the left element of the window

                // Update the range if it's smaller
                if ((val2 - val1) < (maxval - minval)) {
                    minval = val1;
                    maxval = val2;
                }

                // Try shrinking the window from the left
                freqMap[ind1]--;  // Reduce the frequency of the left element's list index
                if (freqMap[ind1] == 0) {
                    freqMap.erase(ind1);  // Remove list index if no elements from that list are in the window
                }
                i++;  // Move the left boundary to the right
            }

            // Expand the window by moving the right boundary to the right
            j++;
        }

        return {minval, maxval};
    }
};