class Solution {
public:
    
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastFallTime = 0;
        
        // Determine the farthest position reached by ants moving to the left.
        for (int leftPosition : left) {
            lastFallTime = max(lastFallTime, leftPosition);
        }
        
        // Determine the farthest position reached by ants moving to the right,
        // considering they start from the right end of the plank (n - position).
        for (int rightPosition : right) {
            lastFallTime = max(lastFallTime, n - rightPosition);
        }
        
        return lastFallTime;
    }
};