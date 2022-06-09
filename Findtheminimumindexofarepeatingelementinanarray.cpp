#include <iostream>
#include <unordered_set>
using namespace std;
 
// Function to find the minimum index of the repeating element
int findMinIndex(int arr[], int n)
{
    int minIndex = n;
 
    // create an empty set to store array elements
    unordered_set<int> set;
 
    // traverse the array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // if the element is seen before, update the minimum index
        if (set.find(arr[i]) != set.end()) {
            minIndex = i;
        }
        // if the element is seen for the first time, insert it into the set
        else {
            set.insert(arr[i]);
        }
    }
 
    // invalid input
    if (minIndex == n) {
        return -1;
    }
 
    // return minimum index
    return minIndex;
}
 
int main()
{
    int arr[] = { 5, 6, 3, 4, 3, 6, 4 };
    // int arr[] = { 1, 2, 3, 4, 5, 6 };
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int minIndex = findMinIndex(arr, n);
 
    if (minIndex != n) {
        cout << "The minimum index of the repeating element is " << minIndex;
    }
    else {
        cout << "Invalid Input";
    }
 
    return 0;
}
