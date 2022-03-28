#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
 
// A macro that defines the size of an integer
#define INT_SIZE sizeof(int) * 8
 
// Function to add `x` and `y` in binary
vector<int> add(int x, int y)
{
    int carry = 0;
    int n = INT_SIZE;
 
    // create an array to store the binary sum
    vector<int> arr(n);
 
    for (int i = 0; i < n; i++)
    {
        // if `x` is 1
        if (x & (1 << i))
        {
            if (y & (1 << i))               // if both `x` and `y` are 1
            {
                if (carry) {
                    arr[n - i - 1] = 1;     // carry = 1
                }
                else {
                    arr[n - i - 1] = 0, carry = 1;
                }
            }
            else                            // `x` is 1, `y` is 0
            {
                if (carry) {
                    arr[n - i - 1] = 0;     // carry = 1
                }
                else {
                    arr[n - i - 1] = 1;     // carry = 0
                }
            }
        }
        // if `x` is 0
        else {
            if (y & (1 << i))               // `x` is 0, `y` is 1
            {
                if (carry) {
                    arr[n - i - 1] = 0;     // carry = 1
                }
                else {
                    arr[n - i - 1] = 1;     // carry = 0
                }
            }
            else                            // both `x` and `y` are 0
            {
                if (carry == 1) {
                    arr[n - i - 1] = 1, carry = 0;
                }
                else {
                    arr[n - i - 1] = 0;     // carry = 0
                }
            }
        }
    }
 
    return arr;
}
 
int main()
{
    int x = 12731, y = 38023;
 
    cout << "x (" << x << ") in binary is " << bitset<32>(x) << endl;
    cout << "y (" << y << ") in binary is " << bitset<32>(y) << endl;
 
    vector<int> arr = add(x, y);
 
    cout << "\nx + y is ";
    for (unsigned i = 0; i < INT_SIZE; i++) {
        cout << arr[i];
    }
 
    return 0;
}