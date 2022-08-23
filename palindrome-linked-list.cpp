#include <bits/stdc++.h> 
using namespace std; 
  
/* Link list node */
struct node { 
    char data; 
    struct node* next; 
}; 
  
// Initial parameters to this function are &head and head 
bool isPalindromeUtil(struct node** left, struct node* right) 
{ 
    /* stop recursion when right becomes NULL */
    if (right == NULL) 
        return true; 
  
    /* If sub-list is not palindrome then no need to 
    check for current left and right, return false */
    bool isp = isPalindromeUtil(left, right->next); 
    if (isp == false) 
        return false; 
  
    /* Check values at current left and right */
    bool isp1 = (right->data == (*left)->data); 
  
    /* Move left to next node */
    *left = (*left)->next; 
  
    return isp1; 
} 
  
// A wrapper over isPalindromeUtil() 
bool isPalindrome(struct node* head) 
{ 
    isPalindromeUtil(&head, head); 
} 
  
/* Push a node to linked list. Note that this function 
changes the head */
void push(struct node** head_ref, char new_data) 
{ 
    /* allocate node */
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 
  
// A utility function to print a given linked list 
void printList(struct node* ptr) 
{ 
    while (ptr != NULL) { 
        cout << ptr->data << "->"; 
        ptr = ptr->next; 
    } 
    cout << "NULL\n" ; 
} 
  
/* Driver program to test above function*/
int main() 
{ 
    /* Start with the empty list */
    struct node* head = NULL; 
    char str[] = "abacaba"; 
    int i; 
  
    for (i = 0; str[i] != '\0'; i++) { 
        push(&head, str[i]); 
        printList(head); 
        isPalindrome(head) ? cout << "Is Palindrome\n\n" : cout << "Not Palindrome\n\n"; 
    } 
  
    return 0; 
} 