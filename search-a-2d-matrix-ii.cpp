#include <bits/stdc++.h>
using namespace std;
 
#define M 3
#define N 4
 
bool binarySearch1D(int arr[], int K)
{
    int low = 0;
    int high = N - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
 
        if (arr[mid] == K)
            return true;
 
        if (arr[mid] < K)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
 
bool searchMatrix(int matrix[M][N], int K)
{
    int low = 0;
    int high = M - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
 
        if (K >= matrix[mid][0]
            && K <= matrix[mid][N - 1])
            return binarySearch1D(matrix[mid], K);
 
        if (K < matrix[mid][0])
            high = mid - 1;
        else
            low = mid + 1;
    }
 
    return false;
}
int main()
{
    int matrix[M][N] = { { 1, 3, 5, 7 },
                         { 10, 11, 16, 20 },
                         { 23, 30, 34, 50 } };
    int K = 3;
    if (searchMatrix(matrix, K))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
}