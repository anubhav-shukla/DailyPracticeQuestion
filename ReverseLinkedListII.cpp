#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node* next;
};
 
struct Node* reverse(struct Node* head)
{
    struct Node* prev = NULL;
    struct Node* curr = head;
    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
 
Node* reverseBetween(Node* head, int m, int n)
{
    if (m == n)
        return head;
    Node *revs = NULL, *revs_prev = NULL;
    Node *revend = NULL, *revend_next = NULL;
    int i = 1;
    Node* curr = head;
    while (curr && i <= n) {
        if (i < m)
            revs_prev = curr;
        if (i == m)
            revs = curr;
        if (i == n) {
            revend = curr;
            revend_next = curr->next;
        }
        curr = curr->next;
        i++;
    }
    revend->next = NULL;
    revend = reverse(revs);
    if (revs_prev)
        revs_prev->next = revend;
    else
        head = revend;
    revs->next = revend_next;
    return head;
}
 
void print(struct Node* head)
{
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
 
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main()
{
    struct Node* head = NULL;
    push(&head, 70);
    push(&head, 60);
    push(&head, 50);
    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);
    reverseBetween(head, 3, 6);
    print(head);
    return 0;
}
