#include <bits/stdc++.h>
using namespace std;
 

struct Node {
    int key;
    struct Node *left, *right;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
 
    return (temp);
}
 
int cnt = 0;
 
int minCameraSetupUtil(Node* root)
{
    if (root == NULL)
        return 1;
 
    int L = minCameraSetupUtil(
        root->left);
    int R = minCameraSetupUtil(
        root->right);
 
    if (L == 1 && R == 1)
        return 2;
 
    else if (L == 2 || R == 2) {
        cnt++;
        return 3;
    }
 
    return 1;
}
 
void minCameraSetup(Node* root)
{
    int value = minCameraSetupUtil(root);
 
    cout << cnt + (value == 2 ? 1 : 0);
}
 
int main()
{
    Node* root = newNode(0);
    root->left = newNode(0);
    root->left->left = newNode(0);
    root->left->left->left = newNode(0);
    root->left->left->left->right = newNode(0);
 
    minCameraSetup(root);
 
    return 0;
}