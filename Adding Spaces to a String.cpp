#include <string>
#include <vector>

class Solution {
public:
    string addSpaces(std::string s, std::vector<int>& spaces) {
        std::string result;
        int lastIndex = 0;
        
        for (int index : spaces) {
            
            result += s.substr(lastIndex, index - lastIndex);
            // Append a space
            result += ' ';

            lastIndex = index;
        }
        
        result += s.substr(lastIndex);
        
        return result;
    }
};