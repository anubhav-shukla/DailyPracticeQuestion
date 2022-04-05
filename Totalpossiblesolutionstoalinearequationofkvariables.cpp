#include <iostream>
#include <unordered_map>
using namespace std;
 
// Function to count the total number of possible solutions to a
// linear equation of `k` variables
int count(int coeff[], int k, int rhs, auto &lookup)
{
    // if rhs become 0, return 1 (solution found)
    if (rhs == 0) {
        return 1;
    }
 
    // return 0 (solution does not exist) if rhs becomes negative or
    // no coefficient is left
    if (rhs < 0 || k < 0) {
        return 0;
    }
 
    // construct a unique map key from dynamic elements of the input
    string key = to_string(k) + "|" + to_string(rhs);
 
    // if the subproblem is seen for the first time, solve it and
    // store its result in a map
 
    if (lookup.find(key) == lookup.end())
    {
        int include = count(coeff, k, rhs - coeff[k], lookup);  // case 1
 
        int exclude = count(coeff, k - 1, rhs, lookup);         // case 2
 
        // assign total ways by including or excluding the current coefficient
        lookup[key] = include + exclude;
    }
 
    // return solution to the current subproblem
    return lookup[key];
}
 
int main()
{
    // `k` coefficients of the given equation
    int coeff[] = { 1, 2, 3 };
    int k = sizeof(coeff) / sizeof(coeff[0]);
 
    int rhs = 4;
 
    // create a map to store solutions to a subproblem
    unordered_map<string, int> lookup;
 
    cout << "The total number of solutions is " << count(coeff, k - 1, rhs, lookup);
 
    return 0;
}