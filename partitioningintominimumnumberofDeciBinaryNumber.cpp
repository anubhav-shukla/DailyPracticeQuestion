#include <bits/stdc++.h>
using namespace std;
 
int minPartitions(string s) {
        int ans=s[0]-'0';
        for(int i=0;i<s.size();i++)
        {
            if(s[i]-'0'>ans)
                ans=s[i]-'0';
        }
        return ans;
    }
int main(){
    string s = "82734";
    cout<<minPartitions(s);
}