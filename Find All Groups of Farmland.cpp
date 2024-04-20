class Solution {
public:
    // Function to recursively explore and mark farmland
    void solve(int r, int c, int &r2, int &c2, vector<vector<int>>& land, vector<vector<int>>& vis) {
        // Getting the dimensions of the land
        int m = land.size();
        int n = land[0].size();
        
        // Marking the current cell as visited
        vis[r][c] = 1;
        
        // Arrays to represent four possible directions: up, down, left, right
        int dp1[4] = {-1, 1, 0, 0};
        int dp2[4] = {0, 0, -1, 1};
        
        // Iterating through each direction
        for (int i = 0; i < 4; i++) {
            int nr = dp1[i] + r; // New row
            int nc = dp2[i] + c; // New column
            
            // Checking if the new cell is within bounds, is unvisited, and is part of farmland
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && land[nr][nc] == 1 && !vis[nr][nc]) {
                // Updating the maximum row and column encountered so far
                r2 = max(r2, nr);
                c2 = max(c2, nc);
                
                // Recursively exploring the farmland
                solve(nr, nc, r2, c2, land, vis);
            }
        }
    }
    
    // Main function to find all farmland
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // Getting the dimensions of the land
        int m = land.size();
        int n = land[0].size();
        
        // Creating a 2D array to mark visited cells
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        // Vector to store the coordinates of each farmland
        vector<vector<int>> ans;
        
        // Iterating through each cell in the land
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the cell is unvisited and is part of farmland
                if (!vis[i][j] && land[i][j] == 1) {
                    int r2 = i, c2 = j; // Initialize maximum row and column
                    
                    // Recursive function to explore and mark the farmland
                    solve(i, j, r2, c2, land, vis);
                    
                    // Pushing the coordinates of the farmland into the result vector
                    ans.push_back({i, j, r2, c2});
                }
            }
        }
        
        // Returning the vector containing coordinates of all farmland
        return ans;
    }
};