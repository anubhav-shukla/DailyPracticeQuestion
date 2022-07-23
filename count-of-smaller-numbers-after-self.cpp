#include<bits/stdc++.h>
using namespace std;
 
class Node{
     
public:
    int val;
    int count;
    Node* left;
    Node* right;
    Node(int num1, int num2)
    {
        this->val = num1;
        this->count = num2;
        this->left = this->right = NULL;
    }
};
 
int addNode(Node*& root, int value,
                         int countSmaller)
{
     
    if (root == NULL)
    {
        root = new Node(value, 0);
        return countSmaller;
    }
    if (root->val < value)
    {
        return root->count +
       addNode(root->right,
               value,
               countSmaller + 1);
    }
    else
    {
        root->count++;
        return addNode(root->left, value,
                       countSmaller);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int data[] = { 10, 6, 15, 20, 30, 5, 7 };
    int size = sizeof(data) / sizeof(data[0]);
    int ans[size] = {0};
 
    Node* root = NULL;
     
    for(int i = size - 1; i >= 0; i--)
    {
        ans[i] = addNode(root, data[i], 0);
    }
 
    for(int i = 0; i < size; i++)
        cout << ans[i] << " ";
 
    return 0;
}