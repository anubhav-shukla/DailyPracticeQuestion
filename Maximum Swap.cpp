class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<pair<char, int>> v(s.size());  // Store max digit and index for each position
        pair<char, int> max = {s.back(), (int)s.size() - 1};  // Start with the last digit

        // Traverse from the end to the beginning, tracking the max digit seen so far
        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] > max.first) {
                max = {s[i], i};
            }
            v[i] = max;
        }

        // Find the first opportunity to swap and maximize the number
        for (int i = 0; i < s.size(); ++i) {
            if (v[i].first > s[i]) {  // Check if a larger digit exists to swap
                swap(s[i], s[v[i].second]);
                break;  // Only one swap is allowed
            }
        }

        // Convert the modified string back to an integer
        return stoi(s);
    }
};