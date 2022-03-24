#include <iostream>
#include <limits.h>
 
int max(int x, int y) { return (x > y) ? x : y; }
 
int findIndex(int nums[], int n)
{
    if (n <= 2) {
        return -1;
    }
    int left[n];
    left[0] = INT_MIN;
 
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], nums[i - 1]);
    }
    int min_so_far = nums[n-1];
 
    int index = -1;
 
    for (int i = n - 2; i > 0; i--)
    {
        if (left[i] < nums[i] && nums[i] < min_so_far) {
            index = i;
        }
 
        if (min_so_far > nums[i]) {
            min_so_far = nums[i];
        }
    }
 
    return index;
}
 
int main(void)
{
    int nums[] = { 4, 2, 3, 5, 1, 6, 9, 7 };
    int n = sizeof nums / sizeof nums[0];
 
    int index = findIndex(nums, n);
 
    if (index >= 0 && index < n) {
        printf("The required index is %d", index);
    }
    else {
        printf("Invalid Input");
    }
 
    return 0;
}
