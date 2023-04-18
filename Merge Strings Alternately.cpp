class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx = 0;
        string ans;

        while(idx < word1.size() && idx < word2.size()) {
            ans += word1[idx];
            ans += word2[idx];
            idx++;
        }

        ans += word1.substr(idx);
        ans += word2.substr(idx);

        return ans;
    }