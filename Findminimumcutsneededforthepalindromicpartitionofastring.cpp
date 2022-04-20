#include <iostream>
#include <climits>
using namespace std;
 
// Function to check if string `X[i…j]` is a palindrome or not
bool isPalindrome(string X, int i, int j)
{
    while (i <= j)
    {
        if (X[i++] != X[j--]) {
            return false;
        }
    }
    return true;
}
 
// Recursive function to find the minimum cuts needed in a string
// such that each partition is a palindrome
int findMinCuts(string X, int i, int j)
{
    // base case: if starting index `i` and ending index `j` are equal,
    // or `X[i…j]` is already a palindrome.
 
    if (i == j || isPalindrome(X, i, j)) {
        return 0;
    }
 
    // stores the minimum number of cuts needed to partition `X[i…j]`
    int min = INT_MAX;
 
    // take the minimum over each possible position at which the
    // string can be cut
 
    for (int k = i; k <= j - 1; k++)
    {
        // recur to get minimum cuts required in `X[i…k]` and `X[k+1…j]`
        int count = 1 + findMinCuts(X, i, k) + findMinCuts(X, k + 1, j);
 
        if (count < min) {
            min = count;
        }
    }
 
    // return the minimum cuts required
    return min;
}
 
// Wrapper over findMinCuts() function
int findMinimumCuts(string X)
{
    int n = X.length();
 
    // base case
    if (n == 0) {
        return 0;
    }
 
    return findMinCuts(X, 0, n - 1);
}
 
int main()
{
    string X = "BABABCBADCD";       // BAB|ABCBA|DCD
 
    cout << "The minimum cuts required are " << findMinimumCuts(X);
 
    return 0;
}