
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
 
// Below arrays detail all eight possible movements
int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
// The function returns true if it is possible to go to cell `(x, y)`.
// It returns false when the cell is invalid or is different from the target
bool isSafe(vector<vector<int>> &mat, int x, int y, int target)
{
    int M = mat.size();
    int N = mat[0].size();
 
    return (x >= 0 && x < M && y >= 0 && y < N) &&
            mat[x][y] == target;
}
 
// Flood fill using DFS
void floodfill(vector<vector<int>> &mat, int x, int y, int replacement)
{
    int M = mat.size();
    int N = mat[0].size();
 
    // get the target value
    int target = mat[x][y];
 
    // replace current cell value with that of replacement
    mat[x][y] = replacement;
 
    // process all eight adjacent cells of the current cell and
    // recur for each valid cell
 
    for (int k = 0; k < 8; k++)
    {
        // if the adjacent cell at position `(x + row[k], y + col[k])` is
        // valid and has the same value as that of the current cell
 
        if (isSafe(mat, x + row[k], y + col[k], target)) {
            floodfill(mat, x + row[k], y + col[k], replacement);
        }
    }
}
 
// Replace all occurrences of 0 by 1, which are surrounded
// by 1 in a binary matrix
void replaceZeroes(vector<vector<int>> &mat)
{
    // base case
    if (mat.size() == 0) {
        return;
    }
 
    // `M × N` matrix
    int M = mat.size();
    int N = mat[0].size();
 
    // visit all cells in the first and last row of the matrix
    for (int i = 0; i < N; i++)
    {
        if (mat[0][i] == 0) {
            floodfill(mat, 0, i, -1);
        }
 
        if (mat[M - 1][i] == 0) {
            floodfill(mat, M - 1, i, -1);
        }
    }
 
    // visit all cells in the first and last column of the matrix
    for (int i = 0; i < M; i++)
    {
        if (mat[i][0] == 0) {
            floodfill(mat, i, 0, -1);
        }
 
        if (mat[i][N - 1] == 0) {
            floodfill(mat, i, N - 1, -1);
        }
    }
 
    // traverse the given matrix
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // replace every 0 with 1
            if (mat[i][j] == 0) {
                mat[i][j] = 1;
            }
 
            // replace every -1 with 0
            if (mat[i][j] == -1) {
                mat[i][j] = 0;
            }
        }
    }
}
 
// Function to print the matrix
void printMatrix(vector<vector<int>> const &mat)
{
    for (auto &row: mat) {
        for (auto &i: row) {
            cout << setw(3) << i;
        }
        cout << endl;
    }
    cout << endl;
}
 
int main()
{
    vector<vector<int>> mat =
    {
        { 1, 1, 1, 1, 0, 0, 1, 1, 0, 1 },
        { 1, 0, 0, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 0, 1, 1, 0, 1 },
        { 0, 0, 1, 1, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
        { 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 0, 0, 1, 0, 1 },
        { 1, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
 
    replaceZeroes(mat);
    printMatrix(mat);
 
    return 0;
}