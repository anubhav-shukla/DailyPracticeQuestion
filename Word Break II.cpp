class Solution {
public:
    vector<string> results;
    unordered_set<string> dict;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        results.clear();
        dict.clear();
        for (const string& word : wordDict) {
            dict.insert(word);
        }
        backTrack(s, 0, "");
        return results;
    }

    void backTrack(const string& s, int start, string currentSentence) {
        if (start == s.length()) {
            results.push_back(currentSentence.substr(0, currentSentence.length() - 1)); // Remove the last space
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (dict.find(s.substr(start, i - start + 1)) != dict.end()) {
                string temp = currentSentence + s.substr(start, i - start + 1) + " ";
                backTrack(s, i + 1, temp);
            }
        }
    }
};