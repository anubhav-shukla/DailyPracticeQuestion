
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        string word = "#" + needle + "#" + haystack;

        // KMP array
        vector<int> P(n + m + 2, 0);

        P[1] = 0;
        int akt = 0;

        for (int i = 2; i < n + m + 2; i++) {
            // while the next element of the prefix is different - try shorter prefix
            while (akt > 0 && word[akt + 1] != word[i])
                akt = P[akt];
            // if the next element of the prefix is the same - increment
            if (word[akt + 1] == word[i])
                akt++;
            // update the value
            P[i] = akt;
        }

        for (int i = m + 2; i < n + m + 2; i++) {
            // if the fragment of haystack matches the needle
            if (P[i] == m)
                return i - 2 * m - 1; // some index corrections
        }
        
        return -1;
    }
};