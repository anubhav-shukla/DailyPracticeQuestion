#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>>& grid, int row, int col) 
{
    int m = grid.size();
    int n = grid[0].size();
    
    int area = 1;
    
    grid[row][col] = 0;
    
    vector<int> dir({-1,0,1,0,-1});
    
    for (int i = 0; i < 4; i++) 
    {
        int r = row+dir[i], c = col+dir[i+1];
        
        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) 
            area += dfs(grid, r, c);
    }
    return area;
}
int largestIsland(vector<vector<int>> grid)
{
    int m = grid.size();
    int n = grid[0].size();
    
    int maxArea = 0;
    
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            if (grid[i][j] == 1) 
            maxArea = max(maxArea, dfs(grid, i, j));
            
    return maxArea;    
}
int main()
{
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,1,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,1,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    
    
    cout<<"Area of largest island = "<<largestIsland(grid);
    
    return 0;
}