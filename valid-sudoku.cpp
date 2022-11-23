    bool checkrow(vector<vector<char>> board, int c)
    {
        set<char> s;
        int count = 0;
        for(int i = 0; i < 9; i++)
        {
            if(board[c][i] != '.')
            {
                count++;
                s.insert(board[c][i]);
            }
        }
        return count == s.size();
    }
    
    bool checkcol(vector<vector<char>> board, int r)
    {
        set<char> s;
        int count = 0;
        for(int i = 0; i < 9; i++)
        {
            if(board[i][r] != '.')
            {
                count++;
                s.insert(board[i][r]);
            }
        }
        return count == s.size();
    }
    
   bool checksqu(vector<vector<char>> board, int r, int c)
    {
        set<char> s;
        int count = 0;
        for(int i = r; i < r+3; i++)
        {
            for(int j = c; j < c+3; j++)
            {
                if(board[i][j] != '.')
                {
                    count++;
                    s.insert(board[i][j]);
                }    
            }            
        }
        return count == s.size();
    }
    
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
         for(int i = 0; i < 9; i++)
         {
            if(!checkrow(board,i))
            {
                return false;
            }
         }
        for(int i = 0; i < 9; i++)
         {
            if(!checkcol(board,i))
            {
                return false;
            }
         }
        for(int i = 0; i < 7; i = i + 3)
        {
            for(int j = 0; j < 7; j = j + 3)
            {
                if(!checksqu(board,i,j))
                    return false;
            }
        }
        return true;
    }