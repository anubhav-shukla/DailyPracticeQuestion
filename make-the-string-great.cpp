

#include <bits/stdc++.h> 
using namespace std;

 string makeGood(string s) {
        int i=1;
        while(i<s.length()){
            if(s[i]==s[i-1]+32 || s[i]+32==s[i-1]){
                for(int j=i-1;j<s.length()-1;j++){
                    s[j]=s[j+2];
                }
                s.resize(s.length()-2);
                i=1;
            }
            else{
                i++;
            }
        }
        return s;
    }

    int main(){
       string s = "leEeetcode";
       cout<<makeGood(s);
    }