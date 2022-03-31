#include <stdio.h>
 
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
 
int min(int x, int y) {
    return (x < y) ? x : y;
}
 
void reverse_subarray(int arr[], int i, int j)
{
    while (i < j)
    {
        swap(arr, i, j);
        i++, j--;
    }
}
 
void reverse(int arr[], int beg, int end, int m)
{
    if (m <= 1) {
        return;
    }
 
    if (m > end - beg + 1) {
        return;
    }
 
    for (int i = beg; i <= end; i = i + m)
    {
        if (i + m - 1 <= end) {
            reverse_subarray(arr, i, i + m - 1);
        }
    }
}
 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
 
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int m = 3;
    int beg = 1, end = 8;
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    reverse(arr, beg, min(end, n - 1), m);
 
    printArray(arr, n);
 
    return 0;
}
