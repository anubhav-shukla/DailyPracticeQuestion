#include <iostream>
#include <vector>
using namespace std;
 
// A Linked List Node
struct Node
{
    int data;
    Node *next;
 
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
 
// Utility function to print contents of a linked list
void printList(Node* node)
{
    while (node != nullptr)
    {
        cout << node->data << " —> ";
        node = node->next;
    }
    cout << "nullptr";
}
 
// Takes two lists sorted in increasing order and merge their nodes
// to make one big sorted list returned
Node *sortedMerge(Node* a, Node* b)
{
    // base cases
    if (a == nullptr) {
        return b;
    }
 
    else if (b == nullptr) {
        return a;
    }
 
    Node *result;
 
    // pick either `a` or `b`, and recur
    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
 
    return result;
}
 
// The main function to merge given `k` sorted linked lists.
// It takes array `lists` of size `k` and generates the sorted output
Node *mergeKLists(vector<Node*> lists)
{
    int k = lists.size();
 
    // base case
    if (k == 0) {
        return nullptr;
    }
 
    int last = k - 1;
 
    // repeat until only one list is left
    while (last != 0)
    {
        int i = 0, j = last;
 
        // `(i, j)` forms a pair
        while (i < j)
        {
            // merge list `j` with `i`
            lists[i] = sortedMerge(lists[i], lists[j]);
 
            // consider the next pair
            i++, j--;
 
            // if all pairs are merged, update last
            if (i >= j) {
                last = j;
            }
        }
    }
 
    return lists[0];
}
 
int main()
{
    int k = 3;    // total number of linked lists
 
    // an array to store the head nodes of the linked lists
    vector<Node*> lists(k);
 
    lists[0] = new Node(1);
    lists[0]->next = new Node(5);
    lists[0]->next->next = new Node(7);
 
    lists[1] = new Node(2);
    lists[1]->next = new Node(3);
    lists[1]->next->next = new Node(6);
    lists[1]->next->next->next = new Node(9);
 
    lists[2] = new Node(4);
    lists[2]->next = new Node(8);
    lists[2]->next->next = new Node(10);
 
    // Merge all lists into one
    Node* head = mergeKLists(lists);
    printList(head);
 
    return 0;
}