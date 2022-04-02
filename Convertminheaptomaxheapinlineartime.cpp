#include <iostream>
#include <vector>
using namespace std;
 
class MaxHeap
{
    int LEFT(int i);
    int RIGHT(int i);
    void heapify(vector<int> &A, int i, int n);
 
public:
    MaxHeap(vector<int> &A);
    int pop(vector<int> &A, int n);
};
int MaxHeap::LEFT(int i) {
    return (2*i + 1);
}
 
int MaxHeap::RIGHT(int i) {
    return (2*i + 2);
}
void MaxHeap::heapify(vector<int> &A, int i, int n)
{
    int left = LEFT(i);
    int right = RIGHT(i);
 
    int largest = i;
 
    if (left < n && A[left] > A[i]) {
        largest = left;
    }
 
    if (right < n && A[right] > A[largest]) {
        largest = right;
    }
    if (largest != i)
    {
        swap(A[i], A[largest]);
        heapify(A, largest, n);
    }
}
 
MaxHeap::MaxHeap(vector<int> &A)
{
    int n = A.size();
 
    int i = (n - 2) / 2;
    while (i >= 0) {
        heapify(A, i--, n);
    }
}
 
int main()
{
    vector<int> A = { 1, 3, 4, 6, 10, 8, 5 };
 
    MaxHeap pq(A);
 
    cout << "The array representation of max-heap is ";
    for (int i: A) {
        cout << i << " ";
    }
 
    return 0;
}
