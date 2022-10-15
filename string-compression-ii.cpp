
#include <bits/stdc++.h>
using namespace std;
int dp[101][101][27][101]; 
int f(int ind, int prev, int count, string &s, int k) {
        if(k < 0) return 1e9;
        if(ind >= s.size()) return 0;
        if(dp[ind][prev][count][k] != -1) return dp[ind][prev][count][k];
        int deleteOperation = f(ind+1, prev, count, s, k-1);
        int notDeleteOperation = 0;
        if(s[ind]-'a' == prev) {
            if(count == 1 || count == 9 || count == 99) notDeleteOperation++;
            notDeleteOperation += f(ind + 1, prev, count + 1, s, k);
        }
        else notDeleteOperation = 1 + f(ind + 1, s[ind]-'a', 1, s, k); 
        return dp[ind][prev][count][k] = min(deleteOperation, notDeleteOperation);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return f(0, 26, 0, s, k);
    }
    int main(){
       string s = "aaabcccd";
       int k = 2;

       cout<<getLengthOfOptimalCompression(s,k);
    }