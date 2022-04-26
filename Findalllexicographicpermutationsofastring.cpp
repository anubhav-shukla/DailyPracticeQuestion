#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
// Function to find all lexicographic permutations of a given
// string where the repetition of characters is allowed
void findLexicographic(string str, string result)
{
    // base condition (permutation found)
    if (result.length() == str.length())
    {
        // print the permutation and return
        cout << result << " ";
        return;
    }
 
    // consider all characters of the string one by one
    for (unsigned i = 0; i < str.length(); i++) {
        findLexicographic(str, result + str[i]);
    }
 
 
    // the above for-loop can be replaced by the following code
 
    /*
    for (int i = 0; i < str.length(); i++)
    {
        result.push_back(str[i]);
        findLexicographic(str, result);
        result.pop_back();            // backtrack
    }
    */
}
 
// Wrapper over `findLexicographic()` function
void findLexicographic(string str)
{
    // base case
    if (str.length() == 0) {
        return;
    }
 
    // to keep track of the result string
    string result;
 
    // sort the string first to print in lexicographical order
    sort(str.begin(), str.end());
 
    findLexicographic(str, result);
}
 
int main()
{
    string str = "ACB";
 
    findLexicographic(str);
 
    return 0;
}