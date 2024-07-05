class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        head = head->next;
        int i = 1, mindist = INT_MAX, prev_i = INT_MIN, first_i = -1;

        while (head->next != nullptr) {
            if ((prev->val < head->val && head->val > head->next->val) || 
                (prev->val > head->val && head->val < head->next->val)) {
                if (prev_i != INT_MIN) {
                    mindist = min(mindist, i - prev_i);
                }
                if (first_i == -1) {
                    first_i = i;
                }
                prev_i = i;
            }
            prev = head;
            head 
        if (mindist == INT_MAX) {
            return {-1, -1};
        }

        return {mindist, prev_i - first_i};
    }
};