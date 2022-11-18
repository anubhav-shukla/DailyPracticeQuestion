

#include <bits/stdc++.h>
using namespace std;

 bool isUgly(int n) {
        if(n <= 0) return false;
        // if(n == 1) return true;
        int arr[3] = {2, 3, 5};
        for(int i=0; i<3; i++){
            while(n%arr[i] == 0) n/= arr[i];
        }
        return n == 1;
    }


    int main(){
       int  n = 6;
        cout<<isUgly(n);
    }