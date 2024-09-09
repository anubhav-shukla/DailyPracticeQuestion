class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> vec(m, vector<int>(n, -1)); // Initialize matrix with -1
        int start_row = 0;
        int end_row = m - 1;
        int start_col = 0;
        int end_col = n - 1;

        while (head) {
            // Fill start row
            for (int i = start_col; i <= end_col && head; i++) {
                vec[start_row][i] = head->val;
                head = head->next;
            }
            start_row++;

            // Fill last column
            for (int i = start_row; i <= end_row && head; i++) {
                vec[i][end_col] = head->val;
                head = head->next;
            }
            end_col--;

            // Fill last row
            for (int i = end_col; i >= start_col && head; i--) {
                vec[end_row][i] = head->val;
                head = head->next;
            }
            end_row--;

            // Fill start column
            for (int i = end_row; i >= start_row && head; i--) {
                vec[i][start_col] = head->val;
                head = head->next;
            }
            start_col++;
        }

        return vec;
    }
};