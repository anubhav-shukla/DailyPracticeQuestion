#include <bits/stdc++.h>
using namespace std;


 int longestPalindrome(vector<string>& words) {
        int ans = 0;
        map<string, int> count;
        for(int i = 0; i < words.size(); i++) {
            count[words[i]]++;
        }
        int flag = 1;
        for(auto s: count) {
            string str = s.first;
            reverse(str.begin(), str.end());
            if(str[0] == str[1]) {
                if((s.second&1) && flag) {
                    ans += s.second;
                    flag = 0;
                }
                else {
                    if(s.second%2 == 0) ans += s.second;
                    else ans += s.second-1;
                }
            }
            else ans += min(count[str], s.second);
        }
        ans *= 2;
        return ans;
    }

    int main(){
        vector<string> words={"lc","cl","gg"};
        cout<<longestPalindrome(words);
    }