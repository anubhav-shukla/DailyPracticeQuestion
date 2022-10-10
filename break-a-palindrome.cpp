#include<bits/stdc++.h>
using namespace std;

string breakPlaindrome(string palindrome){
    int n = palindrome.size();
    if(n<2) return "";
    for(int i=0;i<n;i++){
        if(n%2 && i==n/2) continue;
        if(palindrome[i]!='a'){
            palindrome[i]='a';
            return palindrome;
        }
    }
    palindrome[palindrome.size()-1] ='b';
    return palindrome;
}

int main(){
    string ab="abccba";
    cout<<breakPlaindrome(ab);
}