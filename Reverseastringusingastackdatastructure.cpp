#include <iostream>
#include <algorithm>
using namespace std;
 
// Reverse a string using implicit stack (recursion) in C++.
// Note that the string is passed by reference
void reverse(string &str, int i, int j)
{
    if (i < j)
    {
        // swap characters at i'th and j'th index
        swap(str[i], str[j]);
 
        // recur with increasing i'th index by position and
        // decreasing j'th index by one position
        reverse(str, i + 1, j - 1);
    }
}
 
// Wrapper function
void reverse(string &str) {
    reverse(str, 0, str.length() - 1);
}
 
int main()
{
    string str = "Reverse me";
 
    reverse(str);
    cout << str;
 
    return 0;
}