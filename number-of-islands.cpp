 #include <bits/stdc++.h>
using namespace std;
 
 void helper(vector<vector<char>>&grid,int r,int c,int currRow,int currCol){
        if(currRow<0 or currRow==grid.size() or currCol<0 or currCol==grid[0].size() or grid[currRow][currCol] == '0'){
            return;
        }
        grid[currRow][currCol] = '0';
        helper(grid,r,c,currRow+1,currCol);
        helper(grid,r,c,currRow-1,currCol);
        helper(grid,r,c,currRow,currCol+1);
        helper(grid,r,c,currRow,currCol-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c =  r ? grid[0].size() : 0;
        int islands = 0;
        
        for(int i = 0; i < r;i++){
            for(int j = 0; j < c;j++){
                if(grid[i][j] == '1'){
                    islands++;
                    helper(grid,r,c,i,j);
                }
            }
        }
        
        return islands;
    }


    int main(){
  vector<vector<char>> M = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};
     cout<<numIslands(M);


    }