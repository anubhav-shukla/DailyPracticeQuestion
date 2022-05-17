#include <iostream>
#include <string>
using namespace std;
 
// Recursive function to check if the input string matches
// with a given wildcard pattern
bool isMatch(string word, int n, string pattern, int m)
{
    // end of the pattern is reached
    if (m == pattern.size())
    {
        // return true only if the end of the input string is also reached
        return n == word.size();
    }
 
    // if the input string reaches its end, return when the
    // remaining characters in the pattern are all '*'
    if (n == word.size())
    {
        for (int i = m; i < pattern.size(); i++)
        {
            if (pattern[i] != '*') {
                return false;
            }
        }
 
        return true;
    }
 
    // if the current wildcard character is '?' or the current character in
    // the pattern is the same as the current character in the input string
    if (pattern[m] == '?' || pattern[m] == word[n])
    {
        // move to the next character in the pattern and the input string
        return isMatch(word, n + 1, pattern, m + 1);
    }
 
    // if the current wildcard character is '*'
    if (pattern[m] == '*')
    {
        // move to the next character in the input string or
        // ignore '*' and move to the next character in the pattern
        return isMatch(word, n + 1, pattern, m) || isMatch(word, n, pattern, m + 1);
    }
 
    // we reach here when the current character in the pattern is not a
    // wildcard character, and it doesn't match the current
    // character in the input string
    return false;
}
 
// Check if a string matches with a given wildcard pattern
bool isMatch(string word, string pattern) {
    return isMatch(word, 0, pattern, 0);
}
 
int main()
{
    cout << boolalpha;
 
    cout << isMatch("XYXZZXY", "X***Y") << endl;    // true
    cout << isMatch("XYXZZXY", "X*ZZ??") << endl;   // true
    cout << isMatch("XYXZZXY", "*X*X?") << endl;    // true
    cout << isMatch("XYXZZXY", "X***X") << endl;    // false
    cout << isMatch("XYXZZXY", "*") << endl;        // true
 
    return 0;
}
