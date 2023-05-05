class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0, ans = INT_MIN;

        for(int i = 0; i < k; i++) {
            cnt += isVowel(s[i]);
            ans = max(cnt, ans);
        }

        for(int i = k; i < n; i++) {
            cnt -= isVowel(s[i-k]);
            cnt += isVowel(s[i]);
            ans = max(ans, cnt);
        }

        return ans;
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};