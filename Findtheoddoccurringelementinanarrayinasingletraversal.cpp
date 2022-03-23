#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int findOddOccuring(vector<int> const &arr){
    return accumulate(arr.begin(),next(arr.begin(),arr.size()),0,bit_xor<int>());
}

int main(){
    vector<int> arr={4, 3, 6, 2, 6, 4, 2, 3, 4, 3, 3};
    cout<<"The odd occuring element is "<< findOddOccuring(arr);
    return 0;
}
