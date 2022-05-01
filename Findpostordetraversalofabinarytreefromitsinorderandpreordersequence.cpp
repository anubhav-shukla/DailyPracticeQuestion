#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// Recursive function to find postorder traversal of a binary tree
// from its inorder and preorder sequence
void printPostorder(int start, int end,
                vector<int> const &preorder, int &pIndex,
                unordered_map<int, int> &map)
{
    // base case
    if (start > end) {
        return;
    }
 
    // The next element in the preorder sequence will be the root node of
    // subtree formed by sequence inorder[start, end]
    int value = preorder[pIndex++];
 
    // if the current node is a leaf node (no children)
    if (start == end)
    {
        // print the value of the root node and return
        cout << value << ' ';
        return;
    }
 
    // Get the root node index in inorder sequence to determine
    // its left and right subtree boundary
    int i = map[value];
 
    // recur for the left subtree
    printPostorder(start, i - 1, preorder, pIndex, map);
 
    // recur for the right subtree
    printPostorder(i + 1, end, preorder, pIndex, map);
 
    // print the value of the root node
    cout << value << ' ';
}
 
// Find postorder traversal on a given binary tree from its inorder and
// preorder sequence. This function assumes that the input is valid.
// i.e., given inorder and preorder sequence forms a binary tree.
void findPostorder(vector<int> const &inorder, vector<int> const &preorder)
{
    // create a map to efficiently find the index of any element in a
    // given inorder sequence
    unordered_map<int, int> map;
 
    // fill the map
    for (int i = 0; i < inorder.size(); i++) {
        map[inorder[i]] = i;
    }
 
    // `pIndex` stores the index of the next unprocessed node in the preorder sequence.
    // start with the root node (present at 0th index)
    int pIndex = 0;
 
    cout << "Postorder traversal is ";
    printPostorder(0, inorder.size() - 1, preorder, pIndex, map);
}
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /       / \
         /       /   \
        4       5     6
               / \
              /   \
             7     8
    */
 
    vector<int> inorder = { 4, 2, 1, 7, 5, 8, 3, 6 };
    vector<int> preorder = { 1, 2, 4, 3, 5, 7, 8, 6 };
 
    findPostorder(inorder, preorder);
 
    return 0;
}
