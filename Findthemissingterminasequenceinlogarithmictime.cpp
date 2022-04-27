#include <stdio.h>
 
// Function to find a missing term in a sequence
int findMissingTerm(int nums[], int n)
{
    // search space is nums[low…high]
    int low = 0, high = n - 1;
 
    // calculate the common difference between successive elements
    int d = (nums[n - 1] - nums[0]) / n;
 
    // loop till the search space is exhausted
    while (low <= high)
    {
        // find the middle index
        int mid = high - (high - low) / 2;
 
        // check the difference of middle element with its right neighbor
        if (mid + 1 < n && nums[mid + 1] - nums[mid] != d) {
            return nums[mid + 1] - d;
        }
 
        // check the difference of middle element with its left neighbor
        if (mid - 1 >= 0 && nums[mid] - nums[mid - 1] != d) {
            return nums[mid - 1] + d;
        }
 
        // if the missing element lies on the left subarray, reduce
        // our search space to the left subarray nums[low…mid-1]
        if (nums[mid] - nums[0] != (mid - 0) * d) {
            high = mid - 1;
        }
 
        // if the missing element lies on the right subarray, reduce
        // our search space to the right subarray nums[mid+1…high]
        else {
            low = mid + 1;
        }
    }
}
 
int main(void)
{
    int nums[] = { 5, 7, 9, 11, 15 };
    int n = sizeof(nums) / sizeof(nums[0]);
 
    printf("The missing term is %d", findMissingTerm(nums, n));
 
    return 0;
}