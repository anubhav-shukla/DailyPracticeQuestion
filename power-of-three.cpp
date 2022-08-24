
#include <bits/stdc++.h> 
using namespace std; 

bool isPowerOfThree(int n) {
        if(n<=0) return false;
        // if(pow(3,20)<INT_MAX) cout<<"True";          //Experiment which is the highest power of 3 that is in INT range
        // if(pow(3,19)<INT_MAX) cout<<"True";
        return 1162261467%n==0;                         //19th power of 3 is 1162261467
    }

int main(){
    cout<<isPowerOfThree(27);
}
