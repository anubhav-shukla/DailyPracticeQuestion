#include <bits/stdc++.h>
using namespace std;
 
int minSumPath(vector<vector<int> >& A)
{
    int n = A.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int minimum = INT_MAX;
        for (int j = 0; j <= i; j++) {
            if (i == 0 && j == 0) {
                // if both zero means first element
                minimum = min(minimum, A[i][j]);
                continue;
            }
            if (j == i) {
                A[i][j] = A[i][j] + A[i - 1][j - 1];
                minimum = min(minimum, A[i][j]);
                continue;
            }
            int up = A[i][j], down = A[i][j];
            if (j > 0) {
                up += A[i - 1][j - 1];
            }
            else {
                up = INT_MAX;
            }
            down += A[i - 1][j];
            A[i][j] = min(up, down);
            minimum = min(minimum, A[i][j]);
        }
        ans = minimum;
    }
 
    return ans;
}
 
int main()
{
    vector<vector<int> > A{ { 2 }, { 3, 9 }, { 1, 6, 7 } };
    cout << minSumPath(A);
    return 0;
}