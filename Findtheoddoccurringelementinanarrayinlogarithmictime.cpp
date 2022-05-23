#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Function to find an odd occurring element in a given array
int findOddOccuring(vector<int> nums)
{
    // sort the array
    sort(nums.begin(), nums.end());
 
    // traverse the array from the beginning
    int i = 0;
    while (i < nums.size())
    {
        // store the current element
        int curr = nums[i];
 
        // find the count of the current element
        int count = 0;
        while (i < nums.size() && nums[i] == curr)
        {
            count++;
            i++;
        }
 
        // if the count of the current element is odd, return it
        if (count & 1) {
            return curr;
        }
    }
 
    // invalid input
    return -1;
}
 
int main()
{
    vector<int> nums = { 2, 2, 1, 1, 3, 3, 2, 2, 4, 4, 3, 1, 1 };
 
    cout << "The odd occurring element is " << findOddOccuring(nums);
 
    return 0;
}