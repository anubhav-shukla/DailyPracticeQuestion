#include <bits/stdc++.h>
using namespace std;

bool checkPossibility(vector<int>& nums) 
    {
        //finding size of array and storing in n.
        int n=nums.size();
        //checking for n=1 if only 1 element is there it will already sorted
        if(n==1)
            return true;
        //checking for conditions
        bool v = false;
        for(int i=0;i<n-1;i++)
        {
            //In at any point if current number is greater than the next number only once it should occur so after that if you witness this again you need not replace you only need to do it once.
            if(nums[i]>nums[i+1] && !v)
            {
                v = true;
                if(i>0 && nums[i+1]<nums[i-1])
                   nums[i+1]=nums[i];
            }
            else if(nums[i]>nums[i+1])
               return false;
        }
        return true;    
    }
int main(){
    vector<int> vect;
 
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
 cout<<checkPossibility(vect);
}