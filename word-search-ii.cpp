
#include <bits/stdc++.h> 
using namespace std;

struct Node {
        
        string word;
        Node* child[26];
        
        Node() : word("") {
            for (int i = 0; i < 26; ++i)
                child[i] = NULL;
        }
    };
    
    void addWord(Node* root, string word) {
        Node *cur = root;
        for (auto c : word) {
            Node* next = cur->child[c - 'a'];
            if (!next) {
                next = new Node;
                cur->child[c - 'a'] = next;
            }
            cur = next;
        }
        
        cur->word = word;
    }
    
    
    void DFS(vector<vector<char>>& board, int i, int j, Node* trp,
             vector<vector<bool>>& visited, vector<string>& res) {
        // Base cases
        if (i < 0 || i > board.size() - 1|| j < 0 || j > board[0].size() - 1 ||
            !trp || visited[i][j])
            return;
        
        
        Node* tr = trp->child[board[i][j] - 'a'];
        if (!tr)
            return;
        
        if (!tr->word.empty()) {
            res.push_back(tr->word);
            tr->word = ""; // Avoid duplicates
        }
        
        visited[i][j] = true;
        DFS(board, i - 1, j, tr, visited, res);
        DFS(board, i + 1, j, tr, visited, res);
        DFS(board, i, j - 1, tr, visited, res);
        DFS(board, i, j + 1, tr, visited, res);
        visited[i][j] = false;
        
    }
       
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        // Build trie
        Node* trie = new Node;
        for (auto w : words)
            addWord(trie, w);
        
        vector<string> res;
        
        // DFS from each cell
        for (int i = 0 ; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                DFS(board, i, j, trie, visited, res);
            }
        }
        
        return res;
        
    }
 int main(){
    vector<vector<char>> board = {{"o","a","a","n"},{"e","t","a","e"},{"i","h","k","r"},{"i","f","l","v"}};
    vector<string> words = {"oath","pea","eat","rain"};

        cout<<findWords(board,words);
    }
