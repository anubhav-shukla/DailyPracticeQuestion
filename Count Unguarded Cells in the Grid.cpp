class Solution {
public:
    void print(vector<vector<int>> &mat, int m, int n){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << mat[i][j] << ", ";
            }
            cout << endl;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> cells(m, vector<int> (n, 0));
        for(int i = 0; i < walls.size(); i++)  cells[walls[i][0]][walls[i][1]] = -1;
        for(int i = 0; i < guards.size(); i++) cells[guards[i][0]][guards[i][1]] = 2;
        for(int k = 0; k < guards.size(); k++){
            int row = guards[k][0], col = guards[k][1];
            
            int i = row-1;
            // updating north
            while(i >= 0 && cells[i][col] != 2 && cells[i][col] != -1){
                cells[i][col] = 1;
                i--;
            }
           
            //updating south
            i = row + 1;
            while(i < m && cells[i][col] != 2 && cells[i][col] != -1){
                cells[i][col] = 1;
                i++;
            }

            //updating west
            i = col-1;
            while( i >= 0 && cells[row][i] != 2 && cells[row][i] != -1){
                cells[row][i] = 1;
                i--;
            }

            //updating east
            i = col+1;
            while(i < n && cells[row][i] != -1 && cells[row][i] != 2){
                cells[row][i] = 1;
                i++;
            }

        }

        int count = 0;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(cells[i][j] == 0) count++;
        return count;
    }
};