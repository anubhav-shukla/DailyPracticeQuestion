
#include <bits/stdc++.h>
using namespace std;
 
 int main(){
     int arr[] = {1,25,4,3,2,137,4};
     int n = sizeof(arr) / sizeof(arr[0]);
     int k = 3;
     sort(arr, arr + n);
     int ds = arr[n-k];
     cout<<ds;
 }