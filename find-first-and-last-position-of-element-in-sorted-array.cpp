#include <bits/stdc++.h>
using namespace std;
 
void findFirstAndLast(int arr[], int n, int x)
{
    int first, last;
    first = lower_bound(arr, arr + n, x) - arr;
 
    last = upper_bound(arr, arr + n, x) - arr - 1;
 
    if (first == n) {
        first = -1;
        last = -1;
    }
    cout << "First Occurrence = " << first
         << "\nLast Occurrence = " << last;
}
 

int main()
{
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(int);
    int x = 8;
    findFirstAndLast(arr, n, x);
    return 0;
}