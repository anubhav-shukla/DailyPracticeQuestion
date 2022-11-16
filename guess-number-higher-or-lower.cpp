
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */



#include <bits/stdc++.h>
using namespace std;

int guessNumber(int n) {
        
        int start=0;
        int end=n;
        
        while(start<end){
            int mid=start+(end-start)/2;
            
            if(guess(mid)==0)
                return mid;
            else if(guess(mid)==-1)
                end=mid-1;
            else start=mid+1;
        }
        
        
        return start;
        
    }

int main(){
    int n = 10;
     int pick = 6;
    cout<<guessNumber(n);
}