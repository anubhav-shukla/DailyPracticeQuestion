class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Convert time points to minutes
        vector<int> minutes;
        for (const string& time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }
        
        // Sort the time points in minutes
        sort(minutes.begin(), minutes.end());
        
        // Initialize minimum difference to a large number
        int minDiff = INT_MAX;
        
        // Compare the difference between consecutive time points
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Compare the difference between the first and last time point (wrap-around)
        int wrapAroundDiff = (1440 - minutes.back() + minutes.front());
        minDiff = min(minDiff, wrapAroundDiff);
        
        return minDiff;
    }
};