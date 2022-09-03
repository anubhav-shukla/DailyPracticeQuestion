#include <iostream>
using namespace std;
 
// Function to print pairwise absolute
// difference of consecutive elements
    vector<int> result;
    vector<int> numsSameConsecDiff(int n, int k) {
        // Traverse for all nums from 1-9
        for(int i=1;i<=9;i++){
            dfs(n-1,k,i);
        }
        return result;
    }
    
    void dfs(int n,int k,int num){
        // If n==0 add it to the result
        if(n==0){
            result.push_back(num);
            return;
        }
        
        int lastDigit = num%10;
        
        // We can create 2 digits from the previous last digit using lastDigit+k and lastDigit-k
        int nextFirstDigit = lastDigit+k;
        
        // If the new digit is between 0-9 then only consider it
        if(nextFirstDigit<10){
            int newNum = num*10 + nextFirstDigit;
            dfs(n-1,k,newNum);
        }
        
        int nextSecondDigit = lastDigit-k;
         // If the new second digit is between 0-9 then only consider it and check if it's not similar to first digit
        if(nextFirstDigit!=nextSecondDigit && nextSecondDigit>=0){
            int newNum = num*10 + nextSecondDigit;
            dfs(n-1,k,newNum);
        }
        
    }
int main()
{
   int n = 3, k = 7;
 
    cout<<numsSameConsecDiff(n,k);
 
    return 0;
}