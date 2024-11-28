class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> removal(m, vector<int>(n, 1e6));  //store min distance to each cell from {0, 0}

        queue<pair<int, int>> q;
        q.push({0, 0});
        removal[0][0] = 0;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int k=0;k<4;k++){              //find four neighbours
                int nr = r + (k==0) - (k==1);
                int nc = c + (k==2) - (k==3);

                if(nr>=0 && nr<m && nc>=0 && nc<n){      
                    if(removal[nr][nc] > removal[r][c] + grid[nr][nc]){           //update distance to minimum, if possible 
                        removal[nr][nc] = removal[r][c] + grid[nr][nc];
                        q.push({nr, nc});
                    }
                }
            }
        }

        return removal[m-1][n-1];
    }
};