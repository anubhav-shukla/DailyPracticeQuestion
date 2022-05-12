#include <iostream>
#include <stack>
using namespace std;
 
// Utility function to print contents of an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
 
// Utility function to reverse elements of an array
void reverse(int arr[], int n)
{
    // create an empty stack of integers
    stack<int> stack;
 
    // push each array element into a stack
    for (int i = 0; i < n; i++) {
        stack.push(arr[i]);
    }
 
    // start from index 0
    int index = 0;
 
    // pop values from the stack until it becomes empty
    while (!stack.empty())
    {
        // assign each popped item back to the original array
        arr[index++] = stack.top();
        stack.pop();
    }
}
 
int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    reverse(arr, n);
    print(arr, n);
 
    return 0;
}