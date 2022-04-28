#include <iostream>
#include <stack>
using namespace std;
 
class MinStack
{
    // main stack to store elements
    stack<int> s;
 
    // variable to store the minimum element
    int min;
 
public:
 
    // Inserts a given element on top of the stack
    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            min = val;
        }
        else if (val > min) {
            s.push(val);
        }
        else {
            s.push(2*val - min);
            min = val;
        }
    }
 
    // Removes the top element from the stack
    void pop()
    {
        if (s.empty()) {
            cout << "Stack underflow!!" << endl;
            exit(-1);
        }
 
        int top = s.top();
        if (top < min) {
            min = 2*min - top;
        }
        s.pop();
    }
 
    // Returns the minimum element from the stack in constant time
    int getMin() {
        return min;
    }
};
 
int main()
{
    MinStack s;
 
    s.push(6);
    cout << s.getMin() << endl;
 
    s.push(7);
    cout << s.getMin() << endl;
 
    s.push(5);
    cout << s.getMin() << endl;
 
    s.push(3);
    cout << s.getMin() << endl;
 
    s.pop();
    cout << s.getMin() << endl;
 
    s.pop();
    cout << s.getMin() << endl;
 
    return 0;
}
