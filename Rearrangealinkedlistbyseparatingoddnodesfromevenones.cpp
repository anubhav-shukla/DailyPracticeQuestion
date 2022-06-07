#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}
 
// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
// Rearrange a given linked list by separating odd nodes
// from even ones and maintaining their relative order.
// This approach does not use any dummy node.
void rearrangeEvenOdd(struct Node** head)
{
    struct Node *odd = NULL, *oddTail = NULL;
    struct Node *even = NULL, *evenTail = NULL;
 
    struct Node* curr = *head;
 
    while (curr != NULL)
    {
        if (curr->data & 1)        // current node is odd
        {
            // handle head for the first odd node
            if (odd == NULL) {
                odd = oddTail = curr;
            }
            else {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
        }
        else    // current node is even
        {
            // handle head for the first even node
            if (even == NULL) {
                even = evenTail = curr;
            }
            else {
                evenTail->next = curr;
                evenTail = curr;
            }
        }
        curr = curr->next;
    }
 
    // if the list contains at least one even node
    if (even)
    {
        *head = even;
        evenTail->next = odd;
    }
    // special case – list contains all odd nodes
    else {
        *head = odd;
    }
 
    // NULL to terminate the list; otherwise, it will go into an infinite loop
    if (oddTail) {
        oddTail->next = NULL;
    }
}
 
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct Node* head = NULL;
    for (int i = n - 1; i >=0; i--) {
        push(&head, keys[i]);
    }
 
    rearrangeEvenOdd(&head);
    printList(head);
 
    return 0;
}
