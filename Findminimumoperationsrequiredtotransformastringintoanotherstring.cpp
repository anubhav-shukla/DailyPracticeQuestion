#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
 
// Function to find the minimum number of operations required to transform a given
// string into another string
int getMinimumOperations(string first, string second)
{
    // to keep track of the minimum number of operations required
    int count = 0;
 
    // `i` and `j` keep track of the current characters' index in the
    // first and second strings, respectively
 
    // start from the end of the first and second string
    for (int i = first.length() - 1, j = i; i >= 0; i--, j--)
    {
        // if the current character of both strings doesn't match,
        // search for `second[j]` in substring `first[0, i-1]` and
        // increment the count for every move
 
        while (i >= 0 && first[i] != second[j])
        {
            i--;
            count++;
        }
    }
 
    // return the minimum operations required
    return count;
}
 
// Function to determine if the first string can be transformed into
// the second string
bool isTransformable(string first, string second)
{
    // if the length of both strings differs
    if (first.length() != second.length()) {
        return false;
    }
 
    // construct a multiset out of characters in the first and second string
    // (A multiset is used since it allows duplicates)
 
    unordered_multiset<char> chars1(first.begin(), first.end());
    unordered_multiset<char> chars2(second.begin(), second.end());
 
    // return true if both strings have the same set of characters
    return (chars1 == chars2);
}
 
int main()
{
    string first = "ADCB";
    string second = "ABCD";
 
    if (isTransformable(first, second))
    {
        cout << "The minimum operations required to convert the string "
             << first << " to string " << second << " are "
             << getMinimumOperations(first, second);
    }
    else {
        cout << "The string cannot be transformed";
    }
 
    return 0;
}
