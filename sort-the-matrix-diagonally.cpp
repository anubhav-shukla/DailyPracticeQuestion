#include <bits/stdc++.h>
 
using namespace std;
 
// Function to print the matrix
void printArray(int a[2][2], int N){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
 
// Function to sort the major
// diagonal of the matrix
void sortDiagonal(int a[2][2], int N)
{
    // Temporary vector to store diagonal elements
      vector <int> diagonalElements;
   
    // Storing Diagonal Elements into Temporary Vector
    for (int i = 0; i < N; i++) {
        diagonalElements.push_back(a[i][i]);
    }
   
      // Sort the array diagonal elements
      sort(diagonalElements.begin(), diagonalElements.end());
         
    // Insert the sorted diagonal elements to the original Array
    for (int i = 0; i < N; i++) {
        a[i][i] = diagonalElements[i];
    }
}
 
// Driven Code
int main()
{
    int a[2][2] = { { 4, 2 },
                    { 3, 1 } };
 
    // Sort the major Diagonal
    sortDiagonal(a, 2);
      //print Array
    printArray(a, 2);
    return 0;
}
