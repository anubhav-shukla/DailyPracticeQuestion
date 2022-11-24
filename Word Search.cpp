  bool solve(vector<vector<char>>&board,int i,int j,string word,int ind,int r,int c)
    {
          if(ind==word.size()-1)
          return true;
          board[i][j]-=65;
          if(i>0&&board[i-1][j]==word[ind+1]&&solve(board,i-1,j,word,ind+1,r,c))
          return true;
           if(j>0&&board[i][j-1]==word[ind+1]&&solve(board,i,j-1,word,ind+1,r,c))
          return true;
           if(i<r-1&&board[i+1][j]==word[ind+1]&&solve(board,i+1,j,word,ind+1,r,c))
          return true;
           if(j<c-1&&board[i][j+1]==word[ind+1]&&solve(board,i,j+1,word,ind+1,r,c))
          return true;
          board[i][j]+=65;
          return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int r=board.size(),c=board[0].size();
        for(int i=0;i<r;i++)
           for(int j=0;j<c;j++)
               if(board[i][j]==word[0]&&solve(board,i,j,word,0,r,c))
                   return true;
       return false; 
    }