#include <iostream>
#include <string>
using namespace std;
 
// Function to find all n–digit binary numbers having
// more 1's than 0's at any position
void find(string str, int n, int zeros, int ones)
{
    // continue only if the total number of ones is more than equal
    // to the total number of zeroes
    if (ones < zeros) {
        return;
    }
 
    // if the number becomes n–digit, print it
    if (n == 0)
    {
        cout << str << endl;
        return;
    }
 
    // append 1 to the result and recur with one less digit
    find(str + "1", n - 1, zeros, ones + 1);
 
    // append 0 to the result and recur with one less digit
    find(str + "0", n - 1, zeros + 1, ones);
}
 
int main()
{
    // given the total number of digits
    int n = 4;
 
    string str;
    find(str, n, 0, 0);
 
    return 0;
}
