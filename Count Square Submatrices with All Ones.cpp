class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int sol{},n=matrix.size(),m=matrix[0].size();
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!matrix[i][j]){
                    continue;
                }
                if (i>0 && j>0){
                    matrix[i][j]+=std::min (std::min(matrix[i-1][j] ,matrix[i][j-1]) ,matrix[i-1][j-1]);
                }
                sol+=matrix[i][j];
            }
        }
        return sol;
    }
};