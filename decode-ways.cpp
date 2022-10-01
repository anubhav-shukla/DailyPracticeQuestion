 
#include <iostream>
using namespace std;
  
  int numDecodings(string s) {
        int a = 1, b = s[0] != '0';
        for(int i = 1; i < s.size(); ++i) {
            int c = s[i] != '0' ? b : 0;
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] - '1' + 1 < 7))
                c += a;
            a = b; b = c;
        }
        return b;
    }
    int main(){
       string     s = "12";
       cout<<numDecodings(s);
    }