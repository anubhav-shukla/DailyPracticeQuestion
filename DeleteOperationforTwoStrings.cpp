#include <bits/stdc++.h>
using namespace std;
 
int lcs(char* X, char* Y, int m, int n)
{
    int L[m + 1][n + 1];
 
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; j++) {
 
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] +
                          2 * (X[i - 1] - '0');
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    return L[m][n];
}
int findMinCost(char X[], char Y[])
{
    // Find LCS of X[] and Y[]
    int m = strlen(X), n = strlen(Y);
 
    int cost = 0;
 
    for (int i = 0; i < m; ++i)
        cost += X[i] - '0';
 
    for (int i = 0; i < n; ++i)
        cost += Y[i] - '0';
 
    return cost - lcs(X, Y, m, n);
}
 
int main()
{
    char X[] = "3759";
    char Y[] = "9350";
    cout << "Minimum Cost to make two strings "
         << "identical is = " << findMinCost(X, Y);
    return 0;
}