class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.length() == goal.length() && (s == goal || ((s + s).find(goal) != string::npos));
    }
};