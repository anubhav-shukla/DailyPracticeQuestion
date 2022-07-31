#include <bits/stdc++.h>
using namespace std;
 
void preCompute(int arr[], int n, int pre[])
{
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = arr[i] + pre[i - 1];
}
 
int rangeSum(int i, int j, int pre[])
{
    if (i == 0)
        return pre[j];
 
    return pre[j] - pre[i - 1];
}
 
int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int pre[n];
   
    preCompute(arr, n, pre);
    cout << rangeSum(1, 3, pre) << endl;
    cout << rangeSum(2, 4, pre) << endl;
 
    return 0;
}