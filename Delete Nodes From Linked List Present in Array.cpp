class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int , int > mp;
        for(auto ele: nums ){
            mp[ele] =1;
        }
        ListNode * temp = new ListNode(0);
        ListNode * prev = temp;
        ListNode * curr = head;
        while(curr != NULL){
            if(mp[curr->val] != 1 ){
                // add this element into the linked list
                ListNode * newNode = new ListNode(curr->val);
                prev->next = newNode;
                prev = newNode;
            }
            curr =curr->next;
        }
        return temp->next;
    }
};