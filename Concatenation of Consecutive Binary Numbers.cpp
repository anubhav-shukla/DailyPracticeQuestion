
#include <bits/stdc++.h>

using namespace std;
 
// Function to convert decimal number n
// to its binary representation
// stored as an array arr[]

void decBinary(int arr[], int n)
{

    int k = log2(n);

    while (n > 0) {

        arr[k--] = n % 2;

        n /= 2;

    }
}
 
// Function to convert the number
// represented as a binary array
// arr[] into its decimal equivalent

int binaryDec(int arr[], int n)
{

    int ans = 0;

    for (int i = 0; i < n; i++)

        ans += arr[i] << (n - i - 1);

    return ans;
}
 
// Function to concatenate the binary
// numbers and return the decimal result

int concat(int m, int n)
{
 

    // Number of bits in both the numbers

    int k = log2(m) + 1;

    int l = log2(n) + 1;
 

    // Convert the bits in both the integers

    // to the arrays a[] and b[]

    int a[k] = { 0 }, b[l] = { 0 };
 

    // c[] will be the binary array

    // for the result

    int c[k + l] = { 0 };

    decBinary(a, m);

    decBinary(b, n);
 

    // Update the c[] array

    int in = 0;

    for (int i = 0; i < k; i++)

        c[in++] = a[i];

    for (int i = 0; i < l; i++)

        c[in++] = b[i];
 

    // Return the decimal equivalent

    // of the result

    return (binaryDec(c, k + l));
}
 
// Driver code

int main()
{

    int m = 4, n = 5;
 

    cout << concat(m, n);
 

    return 0;
}