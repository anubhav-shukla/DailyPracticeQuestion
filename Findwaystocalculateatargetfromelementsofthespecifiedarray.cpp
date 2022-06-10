#include <iostream>
#include <list>
using namespace std;
 
void printList(list<pair<int, char>> const &list)
{
    for (auto i: list) {
        cout << "(" << i.second << ")" << i.first << " ";
    }
    cout << endl;
}
 
// Print all ways to calculate a target from elements of a specified array
void printWays(int nums[], int n, int sum, int target,
                            list<pair<int, char>> &list)
{
    // base case: if a target is found, print the result list.
    if (sum == target)
    {
        printList(list);
        return;
    }
 
    // base case: no elements are left
    if (n < 0) {
        return;
    }
 
    // ignore the current element
    printWays(nums, n - 1, sum, target, list);
 
    // consider the current element and subtract it from the target
    list.push_back({nums[n], '+'});
    printWays(nums, n - 1, sum + nums[n], target, list);
    list.pop_back();        // backtrack
 
    // consider the current element and add it to the target
    list.push_back({nums[n], '-'});
    printWays(nums, n - 1, sum - nums[n], target, list);
    list.pop_back();        // backtrack
}
 
int main()
{
    // input array and target number
    int nums[] = { 5, 3, -6, 2 };
    int target = 6;
 
    int n = sizeof(nums)/sizeof(nums[0]);
    list<pair<int, char>> list;
 
    printWays(nums, n - 1, 0, target, list);
 
    return 0;
}
