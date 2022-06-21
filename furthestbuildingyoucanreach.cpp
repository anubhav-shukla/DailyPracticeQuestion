
#include <bits/stdc++.h>
using namespace std;
 
# define R 4
# define C 3
 
bool isSafe(int x, int y)
{
    return (x < R && y < C);
}
 
int minJump(int height[R][C], int x, int y)
{
    if (x == R - 1 && y == C - 1)
        return 0;
 
    int diag = INT_MAX;
    if (isSafe(x + 1, y + 1))
        diag = minJump(height, x + 1, y + 1) +
           abs(height[x][y] - height[x + 1][y + 1]);
 
    int down = INT_MAX;
    if (isSafe(x + 1, y))
        down = minJump(height, x + 1, y) +
             abs(height[x][y] - height[x + 1][y]);
 
    int right = INT_MAX;
    if (isSafe(x, y + 1))
        right = minJump(height, x, y + 1) +
              abs(height[x][y] - height[x][y + 1]);
 
    return min({down, right, diag});
}
 
int main()
{
    int height[][C] = { { 5, 4, 2 },
                       { 9, 2, 1 },
                       { 2, 5, 9 },
                       { 1, 3, 11 } };
 
    cout << minJump(height, 0, 0);
    return 0;
}