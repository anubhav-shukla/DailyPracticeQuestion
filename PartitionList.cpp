#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node* next;
};
Node* newNode(int data)
{
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
struct Node* partition(struct Node* head, int x)
{
    struct Node *smallerHead = NULL, *smallerLast = NULL;
    struct Node *greaterLast = NULL, *greaterHead = NULL;
    struct Node *equalHead = NULL, *equalLast = NULL;
 
    while (head != NULL) {
        if (head->data == x) {
            if (equalHead == NULL)
                equalHead = equalLast = head;
            else {
                equalLast->next = head;
                equalLast = equalLast->next;
            }
        }
        else if (head->data < x) {
            if (smallerHead == NULL)
                smallerLast = smallerHead = head;
            else {
                smallerLast->next = head;
                smallerLast = head;
            }
        }
        else // Append to the list of greater values
        {
            if (greaterHead == NULL)
                greaterLast = greaterHead = head;
            else {
                greaterLast->next = head;
                greaterLast = head;
            }
        }
 
        head = head->next;
    }
    if (greaterLast != NULL)
        greaterLast->next = NULL;
    if (smallerHead == NULL) {
        if (equalHead == NULL)
            return greaterHead;
        equalLast->next = greaterHead;
        return equalHead;
    }
 
    if (equalHead == NULL) {
        smallerLast->next = greaterHead;
        return smallerHead;
    }
    smallerLast->next = equalHead;
    equalLast->next = greaterHead;
    return smallerHead;
}
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    /* Start with the empty list */
    struct Node* head = newNode(10);
    head->next = newNode(4);
    head->next->next = newNode(5);
    head->next->next->next = newNode(30);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(50);
 
    int x = 3;
    head = partition(head, x);
    printList(head);
    return 0;
}
 