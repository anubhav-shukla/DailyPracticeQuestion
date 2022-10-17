

#include <bits/stdc++.h>
using namespace std;


bool checkIfPangram(string sentence) {
        int freq[26];
        for(int i=0;i<26;i++) freq[i] = 0;
        for(int i=0;i<sentence.size();i++) freq[sentence[i]- 'a']++;
        for(int i=0;i<26;i++) if(freq[i] < 1) return false;
        
        return true;
    }
     int main(){
       string sentence = "thequickbrownfoxjumpsoverthelazydog";
        cout<<checkIfPangram(sentence);
     }