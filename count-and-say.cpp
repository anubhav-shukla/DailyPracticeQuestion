

#include <bits/stdc++.h>
using namespace std;

void solve(int n, string &ans)
    {
        //base case 
        if(n==1)
        {
            ans = "1";
            return ;
        }
        //call
        solve(n-1, ans);
        
        //operation
        //code for count and say
        string tmp = "";  int cnt = 1;
        int len = ans.length();
        if(len == 1)
        {
            ans = "11";
            return ;
        }
        for(int i=0; i<len-1; i++)
        {
            if(ans[i] == ans[i+1])
            {
                cnt++;
            }
            else
            {
                tmp += to_string(cnt);
                tmp += ans[i];
                cnt = 1;
            }
        }
        if(cnt>1){
            tmp += to_string(cnt);
            tmp += ans[len-1];
        }
        if(ans[len-1] != ans[len-2])
        {
            tmp += to_string(cnt);
            tmp += ans[len-1];
        }
        ans = tmp;  return;   
    }
    
    string countAndSay(int n) {
        string ans = "";
        solve(n, ans);
        return ans;
    }


    int main(){
        int n = 1;
        cout<<countAndSay(n);
    }