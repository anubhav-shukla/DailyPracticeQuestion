class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        for(int i=0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('/0');
    }
    
    void insert(string key) {
        TrieNode* curr = root;
        for(int i=0;i<key.size();i++){
            if(curr->children[key[i]-'a'] == NULL){
                curr->children[key[i]-'a'] = new TrieNode(key[i]);
            }
            curr = curr->children[key[i]-'a'];
        }
        curr->isTerminal = true;
    }
    
    bool search(string key) {
        TrieNode* curr = root;
        for(int i=0;i<key.size();i++){
            if(curr->children[key[i]-'a']!=NULL){
                curr = curr->children[key[i]-'a'];
            }
            else{
                return false;
            }
        }
        return curr->isTerminal;
    }
    
    bool startsWith(string key) {
         TrieNode* curr = root;
        for(int i=0;i<key.size();i++){
            if(curr->children[key[i]-'a']!=NULL){
                curr = curr->children[key[i]-'a'];
            }
            else{
                return false;
            }
        }
        return true;
    }
};