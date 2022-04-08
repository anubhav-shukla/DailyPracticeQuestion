#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
pair<int, int> findOddOccuring(vector<int> const &arr)
{
    int result = 0;
 
    // take XOR of all array elements
    for (int i: arr) {
        result = result ^ i;
    }
 
    // find the position of the rightmost set bit in `result`
    int k = log2(result & -result);
 
    // `x` and `y` are two odd appearing elements
    int x = 0, y = 0;
 
    // split the array into two subarrays
    for (int i: arr)
    {
        // elements that have k'th bit 1
        if (i & (1 << k)) {
            x = x ^ i;
        }
 
        // elements that have k'th bit 0
        else {
            y = y ^ i;
        }
    }
 
    return make_pair(x, y);
}
 
int main()
{
    vector<int> arr = { 4, 3, 6, 2, 4, 2, 3, 4, 3, 3 };
 
    pair<int, int> p = findOddOccuring(arr);
    cout << "The odd occurring elements are " << p.first << " and " << p.second;
 
    return 0;
}