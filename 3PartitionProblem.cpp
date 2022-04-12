#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;
 
// Helper function for solving 3 partition problem.
// It returns true if there exist three subsets with the given sum
bool subsetSum(vector<int> const &S, int n, int a, int b, int c, auto &lookup)
{
    // return true if the subset is found
    if (a == 0 && b == 0 && c == 0) {
        return true;
    }
 
    // base case: no items left
    if (n < 0) {
        return false;
    }
 
    // construct a unique map key from dynamic elements of the input
    string key = to_string(a) + "|" + to_string(b) + "|" + to_string(c) +
                "|" + to_string(n);
 
    // if the subproblem is seen for the first time, solve it and
    // store its result in a map
    if (lookup.find(key) == lookup.end())
    {
        // Case 1. The current item becomes part of the first subset
        bool A = false;
        if (a - S[n] >= 0) {
            A = subsetSum(S, n - 1, a - S[n], b, c, lookup);
        }
 
        // Case 2. The current item becomes part of the second subset
        bool B = false;
        if (!A && (b - S[n] >= 0)) {
            B = subsetSum(S, n - 1, a, b - S[n], c, lookup);
        }
 
        // Case 3. The current item becomes part of the third subset
        bool C = false;
        if ((!A && !B) && (c - S[n] >= 0)) {
            C = subsetSum(S, n - 1, a, b, c - S[n], lookup);
        }
 
        // return true if we get a solution
        lookup[key] = A || B || C;
    }
 
    // return the subproblem solution from the map
    return lookup[key];
}
 
// Function for solving the 3–partition problem. It returns true if the given
// set `S[0…n-1]` can be divided into three subsets with an equal sum.
bool partition(vector<int> const &S)
{
    // total number of items in `S`
    int n = S.size();
 
    // base case
    if (n < 3) {
        return false;
    }
 
    // create a map to store solutions to a subproblem
    unordered_map<string, bool> lookup;
 
    // get the sum of all elements in the set
    int sum = accumulate(S.begin(), S.end(), 0);
 
    // return true if the sum is divisible by 3 and the set `S` can
    // be divided into three subsets with an equal sum
    return !(sum % 3) && subsetSum(S, n - 1, sum/3, sum/3, sum/3, lookup);
}
 
int main()
{
    // Input: a set of integers
    vector<int> S = { 7, 3, 2, 1, 5, 4, 8 };
 
    if (partition(S)) {
        cout << "Set can be partitioned";
    }
    else {
        cout << "Set cannot be partitioned";
    }
 
    return 0;
}