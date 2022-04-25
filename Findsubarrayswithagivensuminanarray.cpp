#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
using namespace std;
 
// Function to print all subarrays with the given sum ending at a given index
void printSubarray(int nums[], int index, vector<int> &input)
{
    for (int j: input)
    {
        cout << "[" << (j + 1) << "…" << index << "] —— { ";
        copy(nums + j + 1, nums + index + 1,
                ostream_iterator<int>(cout, " "));
        cout << "}\n";
    }
}
 
// Function to find subarrays with the given sum in an array
void findSubarrays(int nums[], int n, int target)
{
    // create an empty map of vectors for storing the end index of all
    // subarrays with the sum of elements so far
    unordered_map<int, vector<int>> map;
 
    // To handle the case when the subarray with the given sum starts
    // from the 0th index
    map[0].push_back(-1);
 
    int sum_so_far = 0;
 
    // traverse the given array
    for (int index = 0; index < n; index++)
    {
        // sum of elements so far
        sum_so_far += nums[index];
 
        // check if there exists at least one subarray with the given sum
        auto itr = map.find(sum_so_far - target);
        if (itr != map.end())
        {
            // print all subarrays with the given sum
            printSubarray(nums, index, map[itr->first]);
        }
 
        // insert (target so far, current index) pair into the map of vectors
        map[sum_so_far].push_back(index);
    }
}
 
int main()
{
    int nums[] = { 3, 4, -7, 1, 3, 3, 1, -4 };
    int target = 7;
 
    int n = sizeof(nums)/sizeof(nums[0]);
    findSubarrays(nums, n, target);
 
    return 0;
}