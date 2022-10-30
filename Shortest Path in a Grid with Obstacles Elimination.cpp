   int shortestPath(vector<vector<int>> &grid, int k)
    {

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(k + 1, 0)));
        queue<vector<int>> q;

        q.push({0, 0, k}); // i ,j , k
        int steps = 0;
        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                auto temp = q.front();
                q.pop();
                int x = temp[0];
                int y = temp[1];
                int curr_k = temp[2];

                if (x == m - 1 and y == n - 1)
                {
                    return steps;
                }

                for (auto p : dir)
                {
                    int dx = p.first + x;
                    int dy = p.second + y;
                    if (dx >= 0 && dx < m && dy >= 0 && dy < n)
                    {
                        if (grid[dx][dy] == 0 && !vis[dx][dy][curr_k])
                        {
                            vis[dx][dy][curr_k] = 1;
                            q.push({dx, dy, curr_k});
                        }
                        else if (grid[dx][dy] == 1 && curr_k > 0 && !vis[dx][dy][curr_k - 1])
            //curr_k -1 because when grid[dx][dy]==1 then curr_k will have to decrease by one
                        {
                            vis[dx][dy][curr_k - 1] = 1;
                            q.push({dx, dy, curr_k - 1});
                        }
                    }
                }
            }
            steps++;//incrementing one steps whenever move to another grid block 
        }
        return -1;
    }