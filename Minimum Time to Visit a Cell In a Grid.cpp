class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> minHeap;
        minHeap.push({0, 0, 0});
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> minTime(m, std::vector<int>(n, 100000000));
        std::vector<std::pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        bool haveMove = false;
        while (minHeap.size()) {
            auto [curTime, curRow, curCol] = minHeap.top();
            minHeap.pop(); 
            if (curRow == m - 1 && curCol == n - 1) {
                return curTime;
            }
            for (std::pair<int, int> move : moves) {
                int nextRow = curRow + move.first;
                int nextCol = curCol + move.second;
                if (
                    0 <= std::min(nextRow, nextCol)
                    && nextRow < m && nextCol < n
                ) {
                    if (curTime + 1 < grid[nextRow][nextCol] && !haveMove) {
                        continue;
                    }
                    int nextTime = 0;
                    if (curTime >= grid[nextRow][nextCol]) {
                        nextTime = curTime + 1;
                    } else {
                        int diff = grid[nextRow][nextCol] - curTime;
                        nextTime = (diff % 2? grid[nextRow][nextCol] : grid[nextRow][nextCol] + 1);
                    }
                    if (nextTime < minTime[nextRow][nextCol]) {
                        minTime[nextRow][nextCol] = nextTime;
                        haveMove = true;
                        minHeap.push({nextTime, nextRow, nextCol});
                    }
                    
                }
            }
        }
        return -1;
    }
};