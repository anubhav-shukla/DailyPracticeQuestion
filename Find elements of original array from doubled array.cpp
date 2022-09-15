#include <bits/stdc++.h>
using namespace std;
 
// Function to find the original array
// from the doubled array
vector<int> findOriginal(vector<int>& arr)
{
 
    // Stores the numbers and
    // their frequency
    map<int, int> numFreq;
 
    // Add number with their frequencies
    // in the hashmap
    for (int i = 0; i < arr.size(); i++) {
        numFreq[arr[i]]++;
    }
 
    // Sort the array
    sort(arr.begin(), arr.end());
 
    // Initialize an arraylist
    vector<int> res;
 
    for (int i = 0; i < arr.size(); i++) {
 
        // Get the frequency of the number
        int freq = numFreq[arr[i]];
        if (freq > 0) {
 
            // Element is of original array
            res.push_back(arr[i]);
 
            // Decrement the frequency of
            // the number
            numFreq[arr[i]]--;
 
            int twice = 2 * arr[i];
 
            // Decrement the frequency of
            // the number having double value
            numFreq[twice]--;
        }
    }
 
    // Return the resultant string
    return res;
}
 
// Driver Code
int main()
{
 
    vector<int> arr = { 4, 1, 2, 2, 2, 4, 8, 4 };
    vector<int> res = findOriginal(arr);
 
    // Print the result list
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
 
    return 0;
}