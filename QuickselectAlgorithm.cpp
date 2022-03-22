#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    vector<int> a = { 7, 4, 6, 3, 9, 1 };
    const size_t k = 2;
 
    nth_element(a.begin(), a.begin() + k, a.end());
    cout << "k'th smallest element is " << a[k];
 
    return 0;
}