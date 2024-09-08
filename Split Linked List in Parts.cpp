class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        int siz = 0;
        ListNode* temp = head;
        
        // Calculate the total size of the linked list
        while (temp != nullptr) {
            siz++;
            temp = temp->next;
        }

        int partSize = siz / k;  // Minimum size of each part
        int extra = siz % k;     // Extra nodes to distribute

        temp = head;
        ListNode* prev = nullptr;

        for (int i = 0; i < k && temp != nullptr; ++i) {
            ans[i] = temp;
            int currentPartSize = partSize + (extra > 0 ? 1 : 0);
            extra--;

            // Move temp `currentPartSize` steps forward
            for (int j = 0; j < currentPartSize; ++j) {
                prev = temp;
                temp = temp->next;
            }

            // Break the link for the current part
            if (prev != nullptr) {
                prev->next = nullptr;
            }
        }

        return ans;
    }
};