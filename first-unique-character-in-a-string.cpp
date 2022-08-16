 #include <bits/stdc++.h>
using namespace std;

 int firstUniqChar(string s) {
        vector<int> v(26,0);
        for(auto x: s) v[x - 'a']++;
        for(int i=0;i<s.length();i++)
            if(v[s[i] - 'a'] == 1) return i;
        return -1;
    }


    int main(){
        cout<<firstUniqChar("Anubhav");
    }