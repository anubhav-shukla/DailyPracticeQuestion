#include <bits/stdc++.h>
using namespace std;
 
bool compare(string s1, string s2)
{
    return s1.size() > s2.size();
}
 
bool canbuildword(string& s, bool isoriginalword,
                  map<string, bool>& mp)
{
 
    if (mp.find(s) != mp.end() && mp[s] == 0)
        return false;
 
    if (mp.find(s) != mp.end() && mp[s] == 1
        && isoriginalword == 0) {
        return true;
    }
 
    for (int i = 1; i < s.length(); i++) {
 
        string left = s.substr(0, i);
        string right = s.substr(i);
        if (mp.find(left) != mp.end() && mp[left] == 1
            && canbuildword(right, 0, mp)) {
            return true;
        }
    }
    mp[s] = 0;
    return false;
}
 
string printlongestword(vector<string> listofwords)
{
 
    map<string, bool> mp;
    for (string s : listofwords) {
        mp[s] = 1;
    }
 
    sort(listofwords.begin(), listofwords.end(), compare);
 
    for (string s : listofwords) {
 
        if (canbuildword(s, 1, mp))
            return s;
    }
 
    return "-1";
}
int main()
{
    vector<string> listofwords = { "Anubhav", "Anub", "Anuv",
                                   "Anu" };
    cout << printlongestword(listofwords);
 
    return 0;
}
