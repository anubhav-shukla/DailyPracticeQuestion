#include <iostream>
 
// Function to rearrange an array such that `A[A[i]]` is set to `i`
// for every element `A[i]`
void rearrange(int A[], int n)
{
    // for each element `A[i]`, increment value present at index
    // `(A[i] % n)` by `i×n`
    for (int i = 0; i < n; i++) {
        A[A[i] % n] += i*n;
    }
 
    // traverse the modified array and set `A[i] = A[i]/n`
    for (int i = 0; i < n; i++) {
        A[i] = A[i] / n;
    }
}
 
int main()
{
    int A[] = { 1, 3, 4, 2, 0 };
    int n = sizeof(A) / sizeof(A[0]);
 
    rearrange(A, n);
 
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
 
    return 0;
}