#include <iostream>
#include <unordered_map>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> freq_map;
        
        // Count character frequencies
        for (char c : s) {
            freq_map[c]++;
        }
        
        // Find the first unique character
        for (int i = 0; i < s.length(); ++i) {
            if (freq_map[s[i]] == 1) {
                return i;
            }
        }
        
        // If no unique character is found
        return -1;
    }
};