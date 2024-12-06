class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int currSum = 0, j = 0, cnt = 0;
        sort(banned.begin(), banned.end());
        for (int i = 1; i <= n; i++) {
            if (j == banned.size()) {
                if ((currSum + i) <= maxSum) {
                    cnt++;
                    currSum += i;
                }
            } 
            else if (banned[j] > i) {
                if ((currSum + i) <= maxSum) {
                    cnt++;
                    currSum += i;
                } 
                else
                    break;
            } 
            else {
                while(j != banned.size() and banned[j]==i)
                    j++;
            }
        }
        return cnt;
    }
};