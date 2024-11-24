class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count  = 0;
        bool flag = false;
        long long totalsum = 0;
        int mini = INT_MAX;
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(matrix[i][j] <0){
                    count++;
                }
                else if(matrix[i][j] == 0){
                    flag = true;
                }
                totalsum += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
            }
        }
        if(count%2 == 0 || flag == true){
            return totalsum;
        }
        else{
            return totalsum - 2*mini;
        }
    }
};