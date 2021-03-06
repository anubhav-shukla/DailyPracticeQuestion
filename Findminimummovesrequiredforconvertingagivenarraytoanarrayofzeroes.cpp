#include <stdio.h>
 
// Find the minimum number of moves required for converting a given array
// to an array of zeroes using only the decrement and reduce operation.
int countMoves(int arr[], int n)
{
    // stores the count of minimum moves required
    int min_moves = 0;
 
    // loop till all the array elements become 0
    while (1)
    {
        // stores count of 0's in the current array
        int no_of_zeroes = 0;
 
        // traverse the array
        for (int i = 0; i < n; i++)
        {
            // convert all odd numbers to even by reducing their value by 1
            // for each odd value, increment the number of moves required
            if (arr[i] % 2 == 1)
            {
                --arr[i];
                ++min_moves;
            }
 
            // increment zeroes count if the current element becomes 0
            if (arr[i] == 0) {
                no_of_zeroes++;
            }
        }
 
        // break the loop if elements in the array become 0
        if (no_of_zeroes == n) {
            break;
        }
 
        // Since each array element is even at this point,
        // divide each element by 2
        for (int j = 0; j < n; j++) {
            arr[j] = arr[j] / 2;
        }
 
        // increment number of moves by 1 for the above divide operation
        min_moves++;
    }
 
    // return count of minimum moves required
    return min_moves;
}
 
int main(void)
{
    int arr[] = { 8, 9, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("The minimum moves required is %d", countMoves(arr, n));
 
    return 0;
}
Download