class Solution {
public:
 int maxi,mini,col_index;
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
       int rows=matrix.size();
       int cols=matrix[0].size();
       for(int i=0;i<rows;i++){
          mini=*min_element(matrix[i].begin(),matrix[i].end());
         auto it=find(matrix[i].begin(),matrix[i].end(),mini);
          col_index=distance(matrix[i].begin(),it);
          maxi=INT_MIN;
        for(int j=0;j<rows;j++){
            maxi=max(maxi,matrix[j][col_index]);
        }
        if(maxi==mini)return {maxi};
       }
       return{};
    }   
};