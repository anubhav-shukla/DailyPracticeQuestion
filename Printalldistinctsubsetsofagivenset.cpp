#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Function to print the elements of a vector
void printVector(vector<int> const &input)
{
    cout << "[";
    int n = input.size();
    for (int i: input) {
        cout << i;
        if (--n) {
            cout << ", ";
        }
    }
    cout << "]\n";
}
 
// Recursive function to print all distinct subsets of `S`.
// `S`   ——> input set
// `out` ——> vector to store subset
// `i`   ——> index of next element in set `S` to be processed
void printPowerSet(vector<int> &S, vector<int> &out, int i)
{
    // if all elements are processed, print the current subset
    if (i < 0)
    {
        printVector(out);
        return;
    }
 
    // include the current element in the current subset and recur
    out.push_back(S[i]);
    printPowerSet(S, out, i - 1);
 
    // backtrack: exclude the current element from the current subset
    out.pop_back();
 
    // remove adjacent duplicate elements
    while (S[i] == S[i-1]) {
        i--;
    }
 
    // exclude the current element from the current subset and recur
    printPowerSet(S, out, i - 1);
}
 
// Wrapper over `printPowerSet()` function
void findPowerSet(vector<int> S)        // no-ref, no-const
{
    // sort the set
    sort(S.begin(), S.end());
 
    // create an empty vector to store elements of a subset
    vector<int> out;
    printPowerSet(S, out, S.size() - 1);
}
 
int main()
{
    vector<int> S = { 1, 3, 1 };
    findPowerSet(S);
 
    return 0;
}
