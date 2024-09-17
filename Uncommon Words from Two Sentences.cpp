#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> count;
        string temp = "";

        for (char ch : s1) {
            if (ch != ' ') {
                temp += ch;
            } else {
                count[temp]++;
                temp = "";
            }
        }
        // add the last word
        if (!temp.empty()) {
            count[temp]++;
        }

        temp = "";  
        for (char ch : s2) {
            if (ch != ' ') {
                temp += ch;
            } else {
                count[temp]++;
                temp = "";
            }
        }

        if (!temp.empty()) {
            count[temp]++;
        }

    
        for ( auto entry : count) {
            if (entry.second == 1) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};
