class Solution {
private:
    int map[26] = {0};
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
          return false;
        }

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            map[idx]++;
        }

        for (int j = 0; j < t.size(); j++) {
            int idx = t[j] - 'a';
            map[idx]--;
        }

        for (int k = 0; k < 26; k++) {
            if (map[k] != 0)
                return false;
        }
        return true;
    }
};