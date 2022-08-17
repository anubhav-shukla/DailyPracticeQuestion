 #include <bits/stdc++.h>
using namespace std; 
 
 
 int uniqueMorseRepresentations(vector<string>& words) {
        string letter[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> st;
        string s;
        
        for(auto &w: words) {
            for(int i=0; i<w.size(); i++) {
                s += letter[w[i]-'a'];
            }
            st.insert(s);
            s.clear();
        }
        
        return st.size();
    }

int main(){
    vector<string> words = {"gin","zen","gig","msg"};
        cout<<uniqueMorseRepresentations(words);
    }
