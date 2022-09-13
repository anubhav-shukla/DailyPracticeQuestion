#include <bits/stdc++.h>
using namespace std;


 bool validUtf8(vector<int>& data) {
        int n = data.size();
        vector<string> temp;

        for(auto i: data) 
        {
            bitset<8> a = i;
            string str = a.to_string();
            temp.push_back(str);
        }           
        
        int numberOfBytes;

        int flag = 0;
        for(int i = 0; i < n; i++)
        {
            if(!flag)
            {
                numberOfBytes = temp[i].find('0');
                if(numberOfBytes == -1) // 0 not present in string, i.e 255 present
                    return false;
                if(numberOfBytes > 1 && numberOfBytes <= 4)
                {
                    flag = 1; 
                    continue;  // important!!!
                }                    
            }            
            if(flag && numberOfBytes > 1 && numberOfBytes <= 4)
            {
                if(!(temp[i][0] == '1' && temp[i][1] == '0'))
                    return false;
                numberOfBytes--;
                if(numberOfBytes == 1)
                    flag = 0;
            }            
            else if(!flag && (!numberOfBytes || numberOfBytes == 1))
            {
                if(!(temp[i][0] == '0'))
                    return false;
            }            
            else if(!flag && numberOfBytes > 4)
                return false;
        }        
        
        return numberOfBytes <= 1; //checking all bytes 1 to 4 present in data if not present then number of Bytes > 1 in that case return false
    }

    int main(){
        vector<int> data = {197,130,1};
        cout<<validUtf8(data);
    }