#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
 
void findPair(int arr[], int n, int diff)
{
    sort(arr, arr + n);
 
    unordered_set<int> set;
 
    for (int i = 0; i < n; i++)
    {
        while (i+1 < n && arr[i] == arr[i+1]) {
            i++;
        }
 
        if (set.find(arr[i] - diff) != set.end()) {
            cout << "(" << arr[i] << ", " << arr[i] - diff << ")\n";
        }
 
        if (set.find(arr[i] + diff) != set.end()) {
            cout << "(" << arr[i] + diff << ", " << arr[i] << ")\n";
        }
 
        set.insert(arr[i]);
    }
}
 
int main()
{
    int arr[] = { 1, 5, 2, 2, 2, 5, 5, 4};
    int diff = -3;
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    findPair(arr, n, diff);
 
    return 0;
}