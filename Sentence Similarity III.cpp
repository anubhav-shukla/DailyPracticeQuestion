class Solution {
public:
    // Function to split a sentence into words
    vector<string> find(string &s) {
        int n = s.size();       // Get the length of the sentence
        string temp = "";       // Temporary string to store words
        vector<string> ans;     // Vector to store all the words
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {   // If a space is found, we've completed a word
                ans.push_back(temp);  // Add the word to the answer
                temp = "";       // Reset the temporary word string
            } else {
                temp += s[i];    // Otherwise, keep building the current word
            }
        }
        ans.push_back(temp);    // Add the last word after the loop
        return ans;             // Return the list of words
    }

    // Function to check if two sentences are similar
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> a = find(sentence1);  // Get words from sentence1
        vector<string> b = find(sentence2);  // Get words from sentence2
        
        // Ensure a is the smaller sentence by size
        if(a.size() > b.size()) {
            swap(a, b);  // Swap a and b so a is always the smaller one
        }

        int n = a.size(), m = b.size();  // Sizes of both sentences
        int i = 0, j = n - 1;            // Pointers for matching from start and end
        int index = 0;
        
        // Match from the start
        while(i < n && index < m) {
            if(a[i] == b[index]) {  // If words match, move to the next word
                index++;
                i++;
            } else {
                break;  // Stop if words don't match
            }
        }
        
        int newindex = m - 1;
        
        // Match from the end
        while(newindex >= index && j >= 0) {
            if(a[j] == b[newindex]) {  // If words match, move to the previous word
                j--;
                newindex--;
            } else {
                break;  // Stop if words don't match
            }
        }
        
        // If i > j, it means we've successfully matched all words in sentence a
        return i > j;
    }
};