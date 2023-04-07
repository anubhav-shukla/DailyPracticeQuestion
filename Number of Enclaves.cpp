class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int itna_chal_sakte = 0;
        vector<vector<int>> cordinates = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        vector<int> rows = {0, n-1}, cols = {0, m-1};

        for (auto i : rows) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        for (auto j : cols) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (q.size()) {
            int row = q.front().first, col = q.front().second;
            q.pop();

            for (auto i : cordinates) {
                int r = row + i[0];
                int c = col + i[1];

                if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c]) {
                    grid[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        for (auto i : grid) {
            for (auto j : i) if (j) itna_chal_sakte++;
        }

        return itna_chal_sakte;
    }
};