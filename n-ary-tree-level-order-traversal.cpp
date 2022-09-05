#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int> > ans;
int level = 0;
 
struct Node {
    char val;
    vector<Node*> children;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->val = key;
    return temp;
}
 
void levelOrder(Node *root) {
        if (ans.size() == level) ans.push_back({root->val});
        else ans[level].push_back(root->val);
        level++;
        for (Node *n: root->children) levelOrder(n);
        level--;
    }
 
int main()
{
    Node* root = newNode(1);
    root->children.push_back(newNode(3));
    root->children.push_back(newNode(2));
    root->children.push_back(newNode(4));
    root->children[0]->children.push_back(newNode(5));
    root->children[0]->children.push_back(newNode(6));
  
    // LevelOrderTraversal obj;
    levelOrder(root);
    for (auto v : ans) {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
