#include <iostream>
#include <bitset>
using namespace std;
 
// Macros to generate the lookup table (at compile-time)
#define R2(n) n, n + 2*64, n + 1*64, n + 3*64
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )
#define REVERSE_BITS R6(0), R6(2), R6(1), R6(3)
 
// lookup table to store the reverse of each index of the table.
// The macro `REVERSE_BITS` generates the table
unsigned int lookup[256] = { REVERSE_BITS };
 
// Function to reverse bits of `n` using a lookup table
int reverseBits(int n)
{
    // print lookup table (reverse of integer `i`)
    /*
    for (int i = 0; i < 256; i++) {
        cout << i << " reverse is " << (int)lookup[i] << endl;
    }
    */
 
    /* Assuming a 32–bit (4 bytes) integer, break the integer into 8–bit chunks.
       Note mask used `0xff` is `11111111` in binary */
 
    // split, reverse, and rearrange each chunk
 
    int reverse = lookup[n & 0xff] << 24 |      // consider the first 8 bits
        lookup[(n >> 8) & 0xff] << 16 |         // consider the next 8 bits
        lookup[(n >> 16) & 0xff] << 8 |         // consider the next 8 bits
        lookup[(n >> 24) & 0xff];               // consider last 8 bits
 
    return reverse;
}
 
int main()
{
    int n = 1691315356;
 
    cout << n << " in binary is " << bitset<32>(n) << endl;
    cout << "On reversing bits " << bitset<32>(reverseBits(n)) << endl;
 
    return 0;
}
