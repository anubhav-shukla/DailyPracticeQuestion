class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> ballToColor, colorCount;
        for (int i = 0; i < n; i++) {
            int ball = queries[i][0], color = queries[i][1];
            if (ballToColor.count(ball)) {
                int oldColor = ballToColor[ball];
                if (--colorCount[oldColor] == 0) {
                    colorCount.erase(oldColor);
                }
            }
            ballToColor[ball] = color;
            colorCount[color]++;
            result[i] = colorCount.size();
        }
        return result;
    }
};
