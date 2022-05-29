#include <iostream>
#include <climits>
#include <vector>
using namespace std;
 
// Function to check whether (i, x) and (i, y) are valid matrix coordinates
int isValid(int i, int x, int y, int M, int N) {
    return i < M && x >= 0 && x < N && y >= 0 && y < N;
}
 
// Collect maximum coins from cell (i, x) to cell (M-1, 0) and from
// cell (i, y) to cell (M-1, N-1) of a `M × N` matrix
int getMaxCoins(vector<vector<int>> const &mat, int i, int x, int y)
{
    // `M × N` matrix
    int M = mat.size();
    int N = mat[0].size();
 
    // return if either (i, x) or (i, y) is invalid
    if (!isValid(i, x, y, M, N)) {
        return INT_MIN;
    }
 
    // current row is the last row
    if (i == M - 1)
    {
        // destination reached
        if (x == 0 && y == N - 1) {
            return (x == y) ? mat[i][x] : mat[i][x] + mat[i][y];
        }
 
        // destination not reached
        return INT_MIN;
    }
 
    // stores the max number of coins
    int coins = INT_MIN;
 
    /*
      Recur for all possible ways:
        (i, x) —> (i+1, x-1) or (i+1, x) or (i+1, x+1)
        (i, y) —> (i+1, y-1) or (i+1, y) or (i+1, y+1)
    */
 
    coins = max(coins, getMaxCoins(mat, i + 1, x - 1, y - 1));
    coins = max(coins, getMaxCoins(mat, i + 1, x - 1, y));
    coins = max(coins, getMaxCoins(mat, i + 1, x - 1, y + 1));
 
    coins = max(coins, getMaxCoins(mat, i + 1, x, y - 1));
    coins = max(coins, getMaxCoins(mat, i + 1, x, y));
    coins = max(coins, getMaxCoins(mat, i + 1, x, y + 1));
 
    coins = max(coins, getMaxCoins(mat, i + 1, x + 1, y - 1));
    coins = max(coins, getMaxCoins(mat, i + 1, x + 1, y));
    coins = max(coins, getMaxCoins(mat, i + 1, x + 1, y + 1));
 
    // update max number of coins with current cell coins before returning
    if (x == y) {
        return mat[i][x] + coins;
    }
    else {
        return (mat[i][x] + mat[i][y]) + coins;
    }
}
 
int getMaxCoins(vector<vector<int>> const &mat)
{
    // base case
    if (mat.size() == 0) {
        return 0;
    }
 
    // `M × N` matrix
    int N = mat[0].size();
 
    // start with cell (0, 0) and (0, N-1)
    return getMaxCoins(mat, 0, 0, N - 1);
}
 
int main()
{
    vector<vector<int>> mat =
    {
        { 0, 2, 4, 1 },
        { 4, 8, 3, 7 },
        { 2, 3, 6, 2 },
        { 9, 7, 8, 3 },
        { 1, 5, 9, 4 }
    };
 
    cout << "The maximum coins collected is " << getMaxCoins(mat);
 
    return 0;
}