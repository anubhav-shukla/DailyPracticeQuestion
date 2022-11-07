

#include <bits/stdc++.h> 
using namespace std;

 int maximum69Number (int num) {
        int res = 0;
        bool f=false;
        vector<int>v;
        while(num)
        {
            v.push_back(num%10);
            num/=10;
        }
        reverse(v.begin(),v.end());
        for(auto x:v)
        {
            if(!f && x==6)
            {
                res*=10;
                res+=9;
                f = true;
            }
            else{
                res*=10;
                res+=x;
            }
        }
        return res;
    }


    int main(){
        int num = 9669;
        cout<<maximum69Number(num);
    }