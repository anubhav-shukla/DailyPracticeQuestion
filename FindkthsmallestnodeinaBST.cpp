#include <iostream>

struct Node
{
    int data;
    struct Node *left, *right;
};
 
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = key;
    node->left = node->right = NULL;
 
    return node;
}
struct Node* kthSmallest(struct Node* root, int* counter, int k)
{
    if (root == NULL) {
        return NULL;
    }
    struct Node* left = kthSmallest(root->left, counter, k);
    if (left != NULL) {
        return left;
    }
 
    // if the root is k'th smallest node
    if (++(*counter) == k) {
        return root;
    }
 
    return kthSmallest(root->right, counter, k);
}
 
struct Node* findKthSmallest(struct Node* root, int k)
{
    int counter = 0;
 
    return kthSmallest(root, &counter, k);
}
 
int main(void)
{
 
    struct Node* root = newNode(15);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(16);
    root->right->right = newNode(25);
 
    int k = 4;
 
    struct Node* result = findKthSmallest(root, k);
 
    if (result) {
        printf("%d'th smallest node is %d", k, result->data);
    }
    else {
        printf("%d'th smallest node does not exist.", k);
    }
 
    return 0;
}