/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* solve(vector<vector<int>> &grid, int a, int b, int n) {
        if(!n) return nullptr;
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                count += grid[a + i][b + j];
            }
        }
        if(count == n * n) return new Node(1, 1);
        else if(count == 0) return new Node(0, 1);
        Node *root = new Node(1, 0);
        n >>= 1;
        root -> topLeft = solve(grid, a, b, n);
        root -> topRight = solve(grid, a, b + n, n);
        root -> bottomLeft = solve(grid, a + n, b, n);
        root -> bottomRight = solve(grid, a + n, b + n, n);
        return root;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(grid, 0, 0, n);
    }
};