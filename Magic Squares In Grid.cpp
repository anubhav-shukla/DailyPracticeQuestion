class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int i, int j){
      int diag1=grid[i-1][j-1] +grid[i][j] +grid[i+1][j+1];
      int diag2=grid[i-1][j+1] +grid[i][j] +grid[i+1][j-1];
      if(diag1!=diag2)return false;
      for(int r=-1;r<=1;r++){
        int sum1=0;
        int sum2=0;
        for(int c=-1;c<=1;c++){
            sum1+=grid[i+r][j+c];
            sum2+=grid[i+c][j+r];
        }
        if(sum1!=diag1 ||sum2!=diag1)return false;
      }
       set<int> s({1,2,3,4,5,6,7,8,9});
                    for(int r = -1 ; r <= 1 ; r++){
                        for(int c = -1; c <=1 ; c++){
                            s.erase(grid[i + r][j + c]);
                        }
                    }
                    return s.empty();
 
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        if(n<3 ||m<3)return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(grid[i][j]==5 && i>0 && i<n-1 && j>0 && j<m-1){
             
               count+=isMagicSquare(grid,i,j);
                }
              }
            }
            return count;
        }
};