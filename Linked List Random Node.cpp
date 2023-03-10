/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    int n;
    Solution(ListNode* head) {
        ListNode* curr = head;

        while(curr){
            ans.push_back(curr->val);
            curr = curr->next;
        }
        n = ans.size();
    }
    
    int getRandom() {
        int ind = rand()%n;
        return ans[ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */