#include <string>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length();
        int m = searchWord.length();
        int index = 1, i = 0;

        while (i < n) {
            // Check if searchWord matches the prefix of the current word
            if (sentence.substr(i, m) == searchWord) {
                return index;
            }

            // Skip to the next word
            while (i < n && sentence[i] != ' ') {
                i++;
            }
            i++; // Skip the space
            index++;
        }
        return -1; // If no match is found
    }
};
