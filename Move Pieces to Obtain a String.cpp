class Solution {
public:
    bool canChange(string start, string target) {
        // Check if lengths are the same
        if (start.length() != target.length()) {
            return false;
        }

        // Count L's and R's in both strings
        int countLStart = 0, countRStart = 0;
        int countLTarget = 0, countRTarget = 0;

        for (char c : start) {
            if (c == 'L') countLStart++;
            else if (c == 'R') countRStart++;
        }

        for (char c : target) {
            if (c == 'L') countLTarget++;
            else if (c == 'R') countRTarget++;
        }

        // If counts of L's and R's do not match, return false
        if (countLStart != countLTarget || countRStart != countRTarget) {
            return false;
        }

        // Now we need to check the movement constraints
        int n = start.length();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Find the next non-blank character in start
            while (i < n && start[i] == '_') {
                i++;
            }
            // Find the next non-blank character in target
            while (j < n && target[j] == '_') {
                j++;
            }

            // If both indices are out of bounds, we are done
            if (i == n && j == n) {
                return true;
            }

            // If one is out of bounds and the other is not, return false
            if (i == n || j == n) {
                return false;
            }

            // Check if the characters match
            if (start[i] != target[j]) {
                return false;
            }

            // If we have 'L', it must be in the correct position
            if (start[i] == 'L') {
                // 'L' can only move left, so it must not be ahead of the target 'L'
                if (i < j) {
                    return false;
                }
            }

            // If we have 'R', it must be in the correct position
            if (start[i] == 'R') {
                // 'R' can only move right, so it must not be behind the target 'R'
                if (i > j) {
                    return false;
                }
            }

            // Move to the next characters
            i++;
            j++;
        }

        return true;
    }
};

