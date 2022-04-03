#include <iostream>
#include <bitset>
using namespace std;
 
int swap(int n, int p, int q)
{
    if (((n & (1 << p)) >> p) ^ ((n & (1 << q)) >> q))
    {
        n ^= (1 << p);
        n ^= (1 << q);
    }
    return n;
}
 
int main()
{
    int n = 31;
    int p = 2, q = 6;    
    cout << n << " in binary is " << bitset<8>(n) << endl;
    n = swap (n, p, q);
    cout << n << " in binary is " << bitset<8>(n) << endl;
 
    return 0;
}
