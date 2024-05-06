class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* runner = current->next;
            bool removeCurrent = false;

            while (runner != nullptr) {
                if (runner->val > current->val) {
                    removeCurrent = true;
                    break;
                }
                runner = runner->next;
            }

            if (removeCurrent) {
                prev->next = current->next;
            } else {
                prev = current;
            }

            current = current->next;
        }

        return dummy->next;
    }
};
