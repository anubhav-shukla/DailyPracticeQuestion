
#include <bits/stdc++.h> 
using namespace std;

  string orderlyQueue(string s, int k) {
        if(k==1){
            string res=s, start =s;
            string h = s.substr(1)+s[0];
            s=h;
            while(start!=s){
                if(s.compare(res)<0){
                    res=s;
                }
                h = s.substr(1)+s[0];
                s=h;
            }
            return res;
        }
        sort(s.begin(), s.end());
        return s;
    }

    int main(){
       string s = "cba"
        int k = 1;
        cout<<orderlyQueue(s,k);
    }