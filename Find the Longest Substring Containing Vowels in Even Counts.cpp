class Solution {
private:
    int int_of(char vowel) {
        if (vowel == 'a') return 0;
        if (vowel == 'e') return 1;
        if (vowel == 'i') return 2;
        if (vowel == 'o') return 3;
        if (vowel == 'u') return 4;

        // invalid, not a vowel
        return -1;
    }

public:
    int findTheLongestSubstring(string s) {
        string vowels = "aeiou";

        // calculate the parity of the frequency of each vowel in the string
        // 0 - even, 1 - odd
        map <string, int> mp;
        string parity = "00000";

        // initially set to 0 (even)
        mp[parity] = -1;

        int length = 0;

        // calculate the parity for every vowel at every index
        for (int i = 0; i < s.length(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                // update arrangement
                if (parity[int_of(s[i])] == '0')
                    parity[int_of(s[i])] = '1';
                else
                    parity[int_of(s[i])] = '0';
            }

            // if the current arrangement has appeared before, it means that the substring between their indices has even counts of all vowels
            if (mp.find(parity) != mp.end()) {
                length = max(length, i - mp[parity]);
            }
            else
                mp[parity] = i;
        }

        return length;
    }
};