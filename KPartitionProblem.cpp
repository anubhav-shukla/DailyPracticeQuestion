#include <iostream>
#include <numeric>
using namespace std;
 
// Function to check if all subsets are filled or not
bool checkSum(int sumLeft[], int k)
{
    int r = true;
    for (int i = 0; i < k; i++)
    {
        if (sumLeft[i] != 0) {
            r = false;
        }
    }
 
    return r;
}
 
// Helper function for solving `k` partition problem.
// It returns true if there exist `k` subsets with the given sum
bool subsetSum(int S[], int n, int sumLeft[], int A[], int k)
{
    // return true if a subset is found
    if (checkSum(sumLeft, k)) {
        return true;
    }
 
    // base case: no items left
    if (n < 0) {
        return false;
    }
 
    bool result = false;
 
    // consider current item `S[n]` and explore all possibilities
    // using backtracking
    for (int i = 0; i < k; i++)
    {
        if (!result && (sumLeft[i] - S[n]) >= 0)
        {
            // mark the current element subset
            A[n] = i + 1;
 
            // add the current item to the i'th subset
            sumLeft[i] = sumLeft[i] - S[n];
 
            // recur for remaining items
            result = subsetSum(S, n - 1, sumLeft, A, k);
 
            // backtrack: remove the current item from the i'th subset
            sumLeft[i] = sumLeft[i] + S[n];
        }
    }
 
    // return true if we get a solution
    return result;
}
 
// Function for solving k–partition problem. It prints the subsets if
// set `S[0…n-1]` can be divided into `k` subsets with equal sum
void partition(int S[], int n, int k)
{
    // base case
    if (n < k)
    {
        cout << "k-partition of set S is not possible";
        return;
    }
 
    // get the sum of all elements in the set
    int sum = accumulate(S, S + n, 0);
 
    int A[n], sumLeft[k];
 
    // create an array of size `k` for each subset and initialize it
    // by their expected sum, i.e., `sum/k`
    for (int i = 0; i < k; i++) {
        sumLeft[i] = sum/k;
    }
 
    // return true if the sum is divisible by `k` and set `S` can
    // be divided into `k` subsets with equal sum
    bool result = !(sum % k) && subsetSum(S, n - 1, sumLeft, A, k);
 
    if (!result)
    {
        cout << "k-partition of set S is not possible";
        return;
    }
 
    // print all k–partitions
    for (int i = 0; i < k; i++)
    {
        cout << "Partition " << i << " is ";
        for (int j = 0; j < n; j++)
        {
            if (A[j] == i + 1) {
                cout << S[j] << " ";
            }
        }
        cout << endl;
    }
}
 
int main()
{
    // Input: a set of integers
    int S[] = { 7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4 };
 
    // total number of items in `S`
    int n = sizeof(S) / sizeof(S[0]);
    int k = 5;
 
    partition(S, n, k);
 
    return 0;
}
