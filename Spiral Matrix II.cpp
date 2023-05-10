class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int firstRow=0,lastRow=n-1,firstCol=0,lastCol=n-1;
        int count=1,i;
        while(firstRow<=lastRow&&firstCol<=lastCol){
            //First row filling up in that iteration.
            for(i=firstCol;i<=lastCol&&firstRow<=lastRow;i++){
                ans[firstRow][i]=count++;
            }
            firstRow++;
            //Last column filling up in that iteration.
            for(i=firstRow;i<=lastRow&&firstCol<=lastCol;i++){
                ans[i][lastCol]=count++;
            }
            lastCol--;
            //Last row filling up in that iteration.
            for(i=lastCol;i>=firstCol&&firstRow<=lastRow;i--){
                ans[lastRow][i]=count++;
            }
            lastRow--;
            //First column filling up in that iteration.
            for(i=lastRow;i>=firstRow&&firstCol<=lastCol;i--){
                ans[i][firstCol]=count++;
            }
            firstCol++;
        }
        return ans;
    }
};