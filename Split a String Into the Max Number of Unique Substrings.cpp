class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return dfs(s, 0, seen);
    }
private:
    int dfs(const string& s, int start, unordered_set<string>& seen) {
        if (start == s.length())
            return 0;
        int maxCount = 0;

        for (int end = start + 1; end <= s.length(); ++end) {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxCount = max(maxCount, 1 + dfs(s, end, seen));
                seen.erase(substring);
            }
        }
        return maxCount;
    }
};