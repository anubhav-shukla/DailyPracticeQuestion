#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
 
unordered_map<int, int> findFrequency(vector<int> const &nums)
{
    unordered_map<int, int> freq;
 
    auto it = nums.begin();
    while (it != nums.end())
    {
        int val = *it;
 
        auto low = lower_bound(nums.begin(), nums.end(), val);
 
        auto high = upper_bound(nums.begin(), nums.end(), val);
 
        freq[val] = high - low;
 
        it = it + freq[val];
    }
 
    return freq;
}
 
int main()
{
    vector<int> nums { 2, 2, 2, 4, 4, 4, 5, 5, 6, 8, 8, 9 };
 
    unordered_map<int, int> freq = findFrequency(nums);
 
    for (auto pair: freq) {
        cout << pair.first << " occurs " << pair.second << " times\n";
    }
 
    return 0;
}