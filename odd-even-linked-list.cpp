ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* o = head;
    ListNode* e = head->next;
    ListNode* eh = e;
        
    while(e != NULL && e->next != NULL) {
        o->next = e->next;
        e->next = e->next->next;
        o->next->next = eh;
        o = o->next;
        e = e->next;
    }
        
    return head;
        
    }