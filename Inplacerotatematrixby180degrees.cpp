#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
 
void rotateMatrix(vector<vector<int>> &mat)
{
    // `N × N` matrix
    int N = mat.size();
 
    // base case
    if (N == 0) {
        return;
    }
 
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < N; j++) {
            swap(mat[i][j], mat[N - i - 1][N - j - 1]);
        }
    }
 
    if (N & 1)
    {
        for (int j = 0; j < N/2; j++) {
            swap(mat[N/2][j], mat[N/2][N - j - 1]);
        }
    }
}
 
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
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
 
    rotateMatrix(mat);
 
    printMatrix(mat);
 
    return 0;
}