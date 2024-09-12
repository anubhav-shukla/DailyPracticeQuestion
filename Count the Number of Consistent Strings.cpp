#include <unordered_map>

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = words.size();
        std::unordered_map<char, int> allowedChars;
        
        for (char& c : allowed) {
            allowedChars[c] = 1;
        }   

        for (string& word : words) {
            for (char& c : word) {
                if (!allowedChars[c]) {
                    count--;
                    break;
                }
            }
        }

        return count;
    }
};