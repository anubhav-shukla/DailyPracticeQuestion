class Trie{
public:
    bool endOfWord = false;
    array<Trie*, 26> children{};
};



class WordDictionary {
public:

    Trie* root{};
    int maxLength{};

    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        
        Trie* curr = root;
        maxLength = max(maxLength, (int)word.size());

        for(auto i : word){

            if(curr->children[i - 'a'] == nullptr){
                curr->children[i - 'a'] = new Trie();
            }

            curr = curr->children[i - 'a'];
        }

        curr->endOfWord = true;

    }
    
    bool search(string word) {
        
       if(word.size() > maxLength) return false;
       int n = word.size();
       stack<pair<Trie*, int>> dfs{};

       if(word[0] == '.'){
           for(auto i : root->children){
               if(i != nullptr) dfs.push(pair<Trie*, int>(i, 0));
           }
       }
       else{
           if(root->children[word[0] - 'a'] != nullptr) dfs.push(pair<Trie*, int>(root->children[word[0] - 'a'], 0));
       }

        while(!dfs.empty()){

            pair<Trie*, int> curr = dfs.top();
            dfs.pop();

            if(curr.second == n - 1 && curr.first->endOfWord == true) return true;
            if(curr.second == n - 1) continue;

            if(word[curr.second + 1] == '.'){
                for(auto i : curr.first->children){
                    if(i != nullptr) dfs.push(pair<Trie*, int>(i, curr.second + 1));
                }
            }
            else{
                if(curr.first->children[word[curr.second + 1] - 'a'] != nullptr) dfs.push(pair<Trie*, int>(curr.first->children[word[curr.second + 1] - 'a'], curr.second + 1));
            }

        }
        
        return false;
    }
};