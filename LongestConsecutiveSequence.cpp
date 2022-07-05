#include <bits/stdc++.h>
using namespace std;
 int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end()); // this is faster
        
        // for(int i = 0; i<nums.size(); i++)
        // {
        //     s.insert(nums[i]);
        // }
        
        int longest_sequence = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(s.find(nums[i] - 1)!=s.end())
                continue;
            
            else
            {
                int count = 0;
                int current_element = nums[i];
                
                while(s.find(current_element) != s.end())
                {
                    count++;
                    current_element++;
                }
                
                longest_sequence = max(longest_sequence,count);
            }
        }
        
        return longest_sequence;
    }

    int main(){
           vector<int> horizontalCuts ;
    horizontalCuts.push_back(1);
    horizontalCuts.push_back(2); 
    horizontalCuts.push_back(4);
    
    horizontalCuts .push_back(1);
    horizontalCuts .push_back(3);

    cout<<longestConsecutive(horizontalCuts);
    }