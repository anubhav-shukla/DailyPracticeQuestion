#include <iostream>
using namespace std;

    string longestPalindrome(string s) {

        int n=s.length();
        int best_start=0,best_len=1;
        for(int mid=0;mid<n;mid++){
            for(int len=0;mid-len>=0 and mid+len<n;len++){
                if(s[mid-len]==s[mid+len]){
                    int curr_len = 2*len+1;
                    if(curr_len>best_len){
                        best_len=curr_len;
                        best_start=mid-len;
                    }
                }else break;
            }            
        }
       
        for(int mid=0;mid<n;mid++){
            //babad
            for(int len=1;mid-len+1>=0 and mid+len<n;len++){
                if(s[mid-len+1]==s[mid+len]){
                    int curr_len = 2*len;
                    if(curr_len>best_len){
                        best_len=curr_len;
                        best_start=mid-len+1;
                    }
                }else break;                
            }
        }
        return s.substr(best_start,best_len);
    }
    int main(){
        string str = "babad";
        cout<<longestPalindrome(str);
        return 0;
    }
