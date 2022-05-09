#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node *next;
};
 
// Helper function to create a new node of the linked list
struct Node *newNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
 
    return newNode;
}
 
// Helper function to print a given linked list
void printList(char *msg, struct Node *head)
{
    printf("%s", msg);
    while (head)
    {
        printf("%2d —> ", head->data);
        head = head->next;
    }
 
    printf("NULL\n");
}
 
// Function to insert a given node at its correct sorted position into
// a given list sorted in increasing order
void sortedInsert(struct Node** head, struct Node *newNode)
{
    // special case for the head end
    if (*head == NULL || (*head)->data >= newNode->data)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
 
    // locate the node before the point of insertion
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
}
 
// Function to exchange data of the given linked list nodes
void swapData(struct Node *first, struct Node *second)
{
    int data = first->data;
    first->data = second->data;
    second->data = data;
}
 
// Function to in-place merge two sorted linked lists without
// modifying links of the first list.
// Note that the second list is a "reference" pointer to the head node,
// whereas the first list is just a copy of the head node.
 
void mergeLists(struct Node *first, struct Node** second)
{
    // loop till either list runs out
    while (first && *second)
    {
        // compare each element of the first list with the first element
        // of the second list
        if (first->data > (*second)->data)
        {
            // exchange data if the current node of the first list has more value
            // than the first node of the second list
            swapData(first, *second);
 
            // pop the front node from the second list
            struct Node* front = *second;
            *second = (*second)->next;
 
            // insert the front node at its correct place into the second list
            sortedInsert(second, front);
        }
 
        // advance the first list to the next node
        first = first->next;
    }
}
 
int main(void)
{
    // construct the first list
    struct Node* first = newNode(2);
    first->next = newNode(6);
    first->next->next = newNode(9);
    first->next->next->next = newNode(10);
    first->next->next->next->next = newNode(15);
 
    // construct the second list
    struct Node* second = newNode(1);
    second->next = newNode(4);
    second->next->next = newNode(5);
    second->next->next->next = newNode(20);
 
    // print both lists before the merge
    printf("Before Merging:\n\n");
    printList("First List: ", first);
    printList("Second List: ", second);
 
    // merge both lists
    mergeLists(first, &second);
 
    // print both lists after merge
    printf("\n\nAfter Merging:\n\n");
    printList("First List: ", first);
    printList("Second List: ", second);
 
    return 0;
}