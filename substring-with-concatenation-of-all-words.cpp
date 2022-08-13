#include <bits/stdc++.h>
using namespace std;
 
vector<int> findSubstringIndices(string S,
                            const vector<string>& L)
{
 
    int size_word = L[0].size();
 
    int word_count = L.size();
 
    int size_L = size_word * word_count;
 
    vector<int> res;
 
    if (size_L > S.size())
        return res;
 
    unordered_map<string, int> hash_map;
 
    for (int i = 0; i < word_count; i++)
        hash_map[L[i]]++;   
 
    for (int i = 0; i <= S.size() - size_L; i++) {
        unordered_map<string, int> temp_hash_map(hash_map);
 
        int j = i,count=word_count;
 
        while (j < i + size_L) {
 
            string word = S.substr(j, size_word);
 
     if (hash_map.find(word) == hash_map.end()||temp_hash_map[word]==0)
                break;
 
            else
               { temp_hash_map[word]--;count--;}
 
 
            j += size_word;
        }
      
       if (count == 0)
            res.push_back(i);
    }
 
    return res;
}
 
int main()
{
    string S = "barfoothefoobarman";
    vector<string> L = { "foo", "bar" };
    vector<int> indices = findSubstringIndices(S, L);
    for (int i = 0; i < indices.size(); i++)
        cout << indices[i] << " ";
    return 0;
}