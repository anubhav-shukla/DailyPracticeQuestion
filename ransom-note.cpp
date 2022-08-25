
#include <bits/stdc++.h> 
using namespace std; 

bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        for(char a:magazine)
        {
            mp[a]++;
        }
        for(char b:ransomNote)
        {
            if(mp.find(b)==mp.end())
                return false;
            mp[b]--;
            if(mp[b]==0)
            {
                mp.erase(b);
            }
        }
        return true;
    }
    int main(){
        string ransomNote = "aa", magazine = "aab";
    cout<<canConstruct(ransomNote,magazine);
}
