#include <iostream>
#include <vector>
using namespace std;
 
// Below arrays detail all eight possible movements
int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
// check whether cell (x, y) is valid or not
bool isValid(int x, int y, int M, int N) {
    return (x >= 0 && x < M && y >= 0 && y < N);
}
 
// Find the length of the longest path in matrix `mat[][]` with consecutive characters.
// The path should continue from the previous character.
// Here, (i, j) denotes the coordinates of the current cell.
int findMaxLen(vector<vector<char>> const &mat, int x, int y, char previous)
{
    // `M × N` matrix
    int M = mat.size();
    int N = mat[0].size();
 
    // base case: return length 0 if the current cell (x, y) is invalid or
    // the current character is not consecutive to the previous character
    if (!isValid(x, y, M, N) || previous + 1 != mat[x][y]) {
        return 0;
    }
 
    // stores length of the longest path
    int max_length = 0;
 
    // recur for all eight adjacent cells from the current cell
    for (int k = 0; k < 8; k++)
    {
        // visit position (x + row[k], y + col[k]) and find the
        // maximum length from that path
        int len = findMaxLen(mat, x + row[k], y + col[k], mat[x][y]);
 
        // update the length of the longest path if required
        max_length = max(max_length, 1 + len);
    }
 
    return max_length;
}
 
int findMaxLength(vector<vector<char>> const &mat, char ch)
{
    // base case
    if (mat.size() == 0) {
        return 0;
    }
 
    // `M × N` matrix
    int M = mat.size();
    int N = mat[0].size();
 
    // stores length of the longest path
    int max_length = 0;
 
    // traverse the matrix
    for (int x = 0; x < M; x++)
    {
        for (int y = 0; y < N; y++)
        {
            // start from the current cell if its value matches with
            // the given character
            if (mat[x][y] == ch)
            {
                // recur for all eight adjacent cells from the current cell
                for (int k = 0; k < 8; k++)
                {
                    // visit position (x + row[k], y + col[k]) and find the
                    // maximum length from that path
                    int len = findMaxLen(mat, x + row[k], y + col[k], ch);
 
                    // update the length of the longest path if required
                    max_length = max(max_length, 1 + len);
                }
            }
        }
    }
 
    return max_length;
}
 
int main()
{
    // input matrix
    vector<vector<char>> mat =
    {
        { 'D', 'E', 'H', 'X', 'B' },
        { 'A', 'O', 'G', 'P', 'E' },
        { 'D', 'D', 'C', 'F', 'D' },
        { 'E', 'B', 'E', 'A', 'S' },
        { 'C', 'D', 'Y', 'E', 'N' }
    };
 
    // starting character
    char ch = 'C';
 
    cout << "The length of the longest path with consecutive characters "
         << "starting from character " << ch << " is "
         << findMaxLength(mat, ch) << endl;
 
    return 0;
}
