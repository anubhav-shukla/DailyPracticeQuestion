
#include <bits/stdc++.h> 
using namespace std; 





bool reorderedPowerOf2(int n) {
        string givenNumStr = to_string(n);        
        unordered_map<char,long long> givenMap;        
        for(auto ch: givenNumStr) givenMap[ch]++;      
              
        long long curNum = 1;
        string curNumStr = to_string(curNum);
        
        while(curNumStr.size() <= givenNumStr.size()){
			//make map of cur number:
            curNumStr = to_string(curNum);
            unordered_map<char,long long> curMap;        
            for(auto ch: curNumStr) curMap[ch]++;   //O(len(N))
            
            //compare givenMap and curMap:
            if(curMap.size() == givenMap.size()){
                bool isEqual = true;
                for(auto it: curMap){
                    long long freq = it.second;
                    char ch = it.first;
                    
                    if(givenMap.find(ch) == givenMap.end() or givenMap[ch] != freq){
                        isEqual = false;
                        break;
                    } 
                }
                
                if(isEqual) return true;     //true if it matches
            }  
            
			//keep increasing cur number:
            curNum = curNum * 2;    //O(logN)
        }
        
        return false;
    }    

    int main(){
        cout<<reorderedPowerOf2(10);
    }