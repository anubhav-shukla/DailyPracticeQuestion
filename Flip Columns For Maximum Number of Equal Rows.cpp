class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        string pattern = "";
        int maxi = INT_MIN;
        unordered_map<string,int> mp;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0;i<n;i++){
            pattern = "";
            for(int j=0;j<m-1;j++){
                if(matrix[i][j]==matrix[i][j+1]){
                    pattern.push_back('0');
                }else{
                    pattern.push_back('1');
                }
            }
            mp[pattern]++;
            maxi = max(maxi,mp[pattern]);
        }
        return maxi;
    }
};