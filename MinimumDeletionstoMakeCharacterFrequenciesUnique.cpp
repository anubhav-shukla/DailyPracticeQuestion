#include <bits/stdc++.h>
using namespace std;
 
int minDeletions(string s)
{
    // initializing "fre" vector to get count of frequency
    // of each chareacter
    vector<int> fre(26, 0);
    set<int> seen; // initialize a seen hashset to store
                   // occupied frequencies
    int cnt = 0;
 
    for (int i = 0; i < s.length(); i++) {
        fre[s[i] - 'a']++;
    }
 
    for (int i = 0; i < 26; i++) {
 
        // if fre[i] is already present in seen set, we
        // decrement fre[i] and increment cnt;
        while (fre[i] && seen.find(fre[i]) != seen.end()) {
            fre[i]--;
            cnt++;
        }
 
        seen.insert(
            fre[i]); // when frequency of characters become
                     // unique insert it into seen set.
    }
 
    return cnt;
}
int main()
{
    string s = "aaabbbcc";
    cout << minDeletions(s) << endl;
    s = "aab";
    cout << minDeletions(s) << endl;
 
    return 0;
}