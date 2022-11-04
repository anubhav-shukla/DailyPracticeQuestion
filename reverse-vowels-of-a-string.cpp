

#include <bits/stdc++.h>
using namespace std;

string reverseVowels(string s) {
        stack<char> st;
        for(char c:s) 
            if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U')
                st.push(c);
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U') {
                char c = st.top(); st.pop();
                s[i] = c;
            }
        }
        return s;
    }

    int main(){
        string s = "hello";
        cout<<reverseVowels(s);
    }