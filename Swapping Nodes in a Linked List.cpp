class Solution {
private:
    int findLen(ListNode *head){
        ListNode *temp=head;
        int count=0;

        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head)
        return head;

        int len = findLen(head);
        ListNode *first = head;
        ListNode *second = head;

        for(int i=0;i<k-1;i++){
            first=first->next;
        }

        for(int i=0;i<(len-k);i++){
            second=second->next;
        }

        //we need the swap the values only
        swap(first->val,second->val);
        return head;    
    }
};