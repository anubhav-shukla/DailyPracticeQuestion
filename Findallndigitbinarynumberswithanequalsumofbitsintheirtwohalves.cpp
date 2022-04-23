#include <iostream>
#include <string>
using namespace std;
 
// Function to find all n–digit binary numbers with an equal sum of
// first and second half bits in a bottom-up manner
void binarySeq(string left, string right, int n, int diff)
{
    // return if the number is invalid
    if (n > 9) {
        return;
    }
 
    // If the number is less than n–digit, and we can cover the difference
    // with n–digits left
 
    if (n && (2 * abs(diff) <= n))
    {
        // If `n` is odd, recur with mid as 0 and 1
        if (n == 1)
        {
            binarySeq(left, "0" + right, 0, diff);
            binarySeq(left, "1" + right, 0, diff);
            return;
        }
 
        // Special case – binary number should not start with 0
        if (left != "")
        {
            // Append 0 to both left and right half.
            // Both left and the right sum remains unchanged.
 
            binarySeq(left + "0", right + "0", n - 2, diff);
 
            // Append 0 to the left half, 1 to the right half, and minus 1 from `diff`
            // as the right sum is increased by 1
 
            binarySeq(left + "0", right + "1", n - 2, diff - 1);
        }
 
        // Append 1 to the left half, 0 to the right half, and add 1 to `diff`
        // as the left sum is increased by 1
 
        binarySeq(left + "1", right + "0", n - 2, diff + 1);
 
        // Append 1 to both left and right half.
        // Both left and the right sum remains unchanged.
 
        binarySeq(left + "1", right + "1", n - 2, diff);
    }
 
    // If the number becomes n–digit with an equal sum of left and right
    // half, print it
 
    else if (n == 0 && diff == 0) {
        cout << left + right << " ";
    }
}
 
int main()
{
    int n = 6;          // n–digit
 
    string left, right; // stores left and right half of the binary number
    int diff = 0;       // difference between left and right half
 
    binarySeq(left, right, n, diff);
 
    return 0;
}