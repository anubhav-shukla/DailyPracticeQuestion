
class Solution {
public:
    
     ListNode* merge(ListNode* list1, ListNode* list2){
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        ListNode* dummy = new ListNode;
        ListNode* temp = dummy;
            
        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
        
        if(list1)
            temp->next = list1;
        
        if(list2)
            temp->next = list2;
        
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return {};
        int len = lists.size();
        for(int i=0; i<len-1; i++){
            lists[i+1] = merge(lists[i], lists[i+1]);      
        }
        return lists[len-1];
    }
};