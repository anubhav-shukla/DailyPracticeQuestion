#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
 
// Fill a binary matrix with alternating rectangles of 1's and 0's
void processMatrix(vector<vector<int>> &mat)
{
    int M = mat.size();
    int N = mat[0].size();
 
    int top = 0, bottom = M - 1;
    int left = 0, right = N - 1;
    bool flag = 1;
 
    while (true)
    {
        if (left > right) {
            break;
        }
 
        // set the top row
        for (int i = left; i <= right; i++) {
            mat[top][i] = flag;
        }
        top++;
 
        if (top > bottom) {
            break;
        }
 
        // set the right column
        for (int i = top; i <= bottom; i++) {
            mat[i][right] = flag;
        }
        right--;
 
        if (left > right) {
            break;
        }
 
        // set the bottom row
        for (int i = right; i >= left; i--) {
            mat[bottom][i] = flag;
        }
        bottom--;
 
        if (top > bottom) {
            break;
        }
 
        // set the left column
        for (int i = bottom; i >= top; i--) {
            mat[i][left] = flag;
        }
        left++;
 
        // invert the flag for the next run
        flag = !flag;
    }
}
 
int main()
{
    int M = 10;
    int N = 8;
 
    // create `M × N` matrix
    vector<vector<int>> mat(M, vector<int>(N));
 
    // fill the matrix
    processMatrix(mat);
 
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << mat[i][j];
        }
        cout << endl;
    }
 
    return 0;
}
