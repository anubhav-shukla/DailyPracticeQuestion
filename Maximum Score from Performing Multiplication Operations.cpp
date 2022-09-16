#include <bits/stdc++.h>

using namespace std;
 
// Function to calculate
// maximum score recursively

int maxScore(

    int l, int r,

    int prefix_sum[],

    int num)
{
 

    // Base case

    if (l > r)

        return 0;
 

    // Sum of array in range (l, r)

    int current_sum

        = prefix_sum[r]

          - (l - 1 >= 0

                 ? prefix_sum[l - 1]

                 : 0);
 

    // If the operation is even-numbered

    // the score is decremented

    if (num % 2 == 0)

        current_sum *= -1;
 

    // Exploring all paths, by removing

    // leftmost and rightmost element

    // and selecting the maximum value

    return current_sum

           + max(

                 maxScore(

                     l + 1, r,

                     prefix_sum,

                     num + 1),

                 maxScore(

                     l, r - 1,

                     prefix_sum,

                     num + 1));
}
 
// Function to find the max score

int findMaxScore(int a[], int n)
{

    // Prefix sum array

    int prefix_sum[n] = { 0 };
 

    prefix_sum[0] = a[0];
 

    // Calculating prefix_sum

    for (int i = 1; i < n; i++) {

        prefix_sum[i]

            = prefix_sum[i - 1] + a[i];

    }
 

    return maxScore(0, n - 1,

                    prefix_sum, 1);
}
 
// Driver code

int main()
{

    int n = 6;

    int A[n] = { 1, 2, 3, 4, 2, 6 };
 

    cout << findMaxScore(A, n);

    return 0;
}