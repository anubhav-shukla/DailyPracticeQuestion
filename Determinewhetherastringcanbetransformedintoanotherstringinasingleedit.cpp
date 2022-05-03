#include <iostream>
#include <cstdlib>
using namespace std;
 
// Determine if the first string can be transformed into the
// second string with a single edit operation
bool checkEditDistance(string first, string second)
{
    // store length of both strings
    int m = first.length();
    int n = second.length();
 
    // difference between the length of both strings is more than one
    if (abs(m - n) > 1) {
        return false;
    }
 
    // to keep track of the total number of edits
    int edits = 0;
 
    // `i` and `j` keep track of the index of current characters in the
    // first and second strings, respectively
 
    int i = 0, j = 0;
 
    // loop till either string runs out
    while (i < m && j < n)
    {
        // if the current character of both strings doesn't match
        if (first[i] != second[j])
        {
            // when the length of the first string is more than the length
            // of the second string,
            // remove the current character at index `i` in the first string
 
            if (m > n) {
                i++;
            }
 
            // when the length of the first string is less than the length
            // of the second string, add the current character at index `j`
            // in the second string to the first string
 
            else if (m < n) {
                j++;
            }
 
            // when the length of both strings is the same, replace the character
            // present at index `i` in the first string with the character present
            // at index `j` in the second string.
 
            else {
                i++, j++;
            }
 
            // increment the number of edits
            edits++;
        }
 
        // if the current character of both strings matches
        else {
            i++, j++;
        }
    }
 
    // remove any extra characters left in the first string
    if (i < m) {
        edits++;
    }
 
    // add any extra characters left in the second string to
    // the end of the first string
 
    if (j < n) {
        edits++;
    }
 
    // return true if the number of edits is exactly one;
    // return false otherwise
 
    return (edits == 1);
}
 
int main()
{
    cout << boolalpha;
 
    cout << checkEditDistance("xyz", "xz") << endl;     // true
    cout << checkEditDistance("xyz", "xyyz") << endl;   // true
    cout << checkEditDistance("xyz", "xyx") << endl;    // true
    cout << checkEditDistance("xyz", "xxx") << endl;    // false
 
    return 0;
}