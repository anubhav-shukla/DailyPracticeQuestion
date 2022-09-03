#include <iostream>
using namespace std;
 
// Function to print pairwise absolute
// difference of consecutive elements
void pairwiseDifference(int arr[], int n)
{
    int diff;
    for (int i = 0; i < n - 1; i++) {
 
        // absolute difference between
        // consecutive numbers
        diff = abs(arr[i] - arr[i + 1]);
        cout << diff << " ";
    }
}
 
// Driver Code
int main()
{
    int arr[] = { 4, 10, 15, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    pairwiseDifference(arr, n);
 
    return 0;
}