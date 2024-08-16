class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays[0].size();
        int mini = arrays[0][0];
        int maxi = arrays[0][m-1];
        int diff = INT_MIN;
        for(int i=1; i<arrays.size(); i++){
            int size = arrays[i].size();
            int diff1 = (arrays[i][size-1] - mini);
            int diff2 = (maxi - arrays[i][0]);
            if(arrays[i][0] < mini)mini = arrays[i][0];
            if(arrays[i][size-1] > maxi) maxi = arrays[i][size-1];
            diff = max(diff,max(diff1, diff2));
        }
        return diff;
    }
};