class Solution {
public:
void dfs(vector<vector<int>>& island, int row , int col)
{   int n = island.size();
    int m = island[0].size();
      if(row<0 || row>=n || col<0 || col>=m || island[row][col]==-1|| island[row][col]==1)
      return ;

     island[row][col]=-1;
     if(row+1<n && island[row+1][col]==0)
     {
        dfs(island, row+1, col);

     }
     if(row-1>=0 && island[row-1][col]==0)
     {
          dfs(island, row-1, col);
     }
     if(col+1< m&& island[row][col+1]==0)
     {
         dfs(island, row, col+1);
     }
      if(col-1>=0 && island[row][col-1]==0)
     {
         dfs(island, row, col-1);
     }
     return ;
}
   void createisland(vector<vector<int>>& island, vector<string>&grid)
   {
       for(int i =0 ;i< grid.size(); i++)
       {
          string part = grid[i];
          for(int  j =0; j< part.size() ; j++)
          {
              if(part[j]=='/')
              {
                  island[3*i+0][3*j+2]=1;
                  island[3*i+1][3*j+1]=1;
                  island[3*i+2][3*j]=1;
              }
              else if (part[j]=='\\')
              {
                   island[3*i][3*j]=1;
                   island[3*i+1][3*j+1]=1;
                   island[3*i+2][3*j+2]=1;
              }
            }
          }
        
           

       
   }
    int regionsBySlashes(vector<string>& grid) {
        //  grid construct 
        vector<vector<int>>island(3*grid.size(),vector<int>( 3*grid[0].size(), 0) );
        createisland (island, grid);

        int count=0 ;
        for(int i =0;i< island.size() ; i++)
        {
             for(int j =0;j< island[0].size() ; j++)
             {
                 if(island[i][j]==0)
                 {
                    // visit it
                    dfs(island, i, j);
                    count++;
                 }
             }
        }
        return count;
        
    }
};