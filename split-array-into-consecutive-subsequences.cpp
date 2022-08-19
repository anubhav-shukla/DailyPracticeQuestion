  #include <bits/stdc++.h>
using namespace std; 
 
bool isPossible(vector<int>& nums) {
      
        unordered_map<int,int>freq,hMap;
        for(int num:nums)freq[num]++;
        for(int num : nums){
          
    // wont pick num if frequency numbere as there are  not part of new sequence 
            if(freq[num]==0)continue;
            
    // Condition for a Valid Subsequence 
    // if number is present in hypoMap then we can expand in right direction 
                   if(hMap[num]>0){  
                    hMap[num]--;
                    freq[num]--;
                    // storing the next consecutive number 
                    hMap[num+1]++;     
                }
            else  if(freq[num]>0 and freq[num+1]>0 and freq[num+2]>0){
                    freq[num]--;
                    freq[num+1]--;
                    freq[num+2]--;
                    cout<<num<<" "<<num+1<<" "<<num+2<<endl;
// storing next consecutive number into hypothetical map to check for expansion
                    hMap[num+3]++;
                }     
                else return false ;                 
            }      
        return true;
    }


    int main(){
        vector<int> nums = {1,2,3,3,4,5};
        cout<<isPossible(nums);
    }