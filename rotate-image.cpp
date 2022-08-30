#include <bits/stdc++.h>
#define N 4
using namespace std;
 
// An Inplace function to
// rotate a N x N matrix
// by 90 degrees in
// anti-clockwise direction
void rotateMatrix(int mat[][N])
{ // REVERSE every row
    for (int i = 0; i < N; i++)
        reverse(mat[i], mat[i] + N);
 
    // Performing Transpose
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++)
            swap(mat[i][j], mat[j][i]);
    }
}
 
// Function to print the matrix
void displayMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
 
/* Driver program to test above functions */
int main()
{
    // Test Case 1
    int mat[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
 
    // Test Case 2
    /* int mat[N][N] = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                    };
     */
 
    // Test Case 3
    /*int mat[N][N] = {
                    {1, 2},
                    {4, 5}
                };*/
 
    // displayMatrix(mat);
 
    rotateMatrix(mat);
 
    // Print rotated matrix
    displayMatrix(mat);
 
    return 0;
}