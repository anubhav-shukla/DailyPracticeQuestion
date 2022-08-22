 
   #include <bits/stdc++.h>
using namespace std; 


 bool isPowerOfFour(int n) {
        int setBit = 0 , nonBit = 0;
        
        while(n > 0) {
            int bit = n & 1;
            n = n>>1;
            if(bit)
                setBit++;
            else
                nonBit++;
        }
        
        if(setBit == 1 && nonBit%2==0)
            return true;
        return false;
    }

    int main(){
        cout<<isPowerOfFour(6);
    }