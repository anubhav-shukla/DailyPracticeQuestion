#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
 
typedef pair<int, int> Pair;
 
// Function to find two non-overlapping pairs with the same sum in an array
void findPairs(int nums[], int n)
{
    // create an empty map
    // key —> sum of a pair of elements in the array
    // value —> vector storing an index of every pair having that sum
    unordered_map<int, vector<Pair>> map;
 
    // consider every pair (nums[i], nums[j]), where `j > i`
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // calculate the sum of the current pair
            int sum = nums[i] + nums[j];
 
            // if the sum is already present on the map
            if (map.find(sum) != map.end())
            {
                // check every pair for the desired sum
                for (auto pair: map.find(sum)->second)
                {
                    int m = pair.first, n = pair.second;
 
                    // if pairs don't overlap, print and return them
                    if ((m != i && m != j) && (n != i && n != j))
                    {
                        cout << "First Pair (" << nums[i] << ", " << nums[j] << ")\n";
                        cout << "Second Pair (" << nums[m] << ", " << nums[n] << ")\n";
                        return;
                    }
                }
            }
 
            // insert the current pair into the map
            map[sum].push_back({i, j});
        }
    }
 
    cout << "No non-overlapping pairs present";
}
 
int main()
{
    int nums[] = { 3, 4, 7, 3, 4 };
    int n = sizeof(nums) / sizeof(nums[0]);
 
    findPairs(nums, n);
 
    return 0;
}
