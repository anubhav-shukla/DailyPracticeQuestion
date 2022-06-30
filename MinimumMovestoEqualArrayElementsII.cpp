#include <bits/stdc++.h>
using namespace std;
 

int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=n/2;
        int ans=0;
        for(int i=0;i<mid;i++)
            ans+=nums[mid]-nums[i];
        for(int i=nums.size()-1;i>mid;i--)
            ans+=nums[i]-nums[mid];
        return ans;
    }

int main(){
    vector<int> listofwords = { 1,2,3,4,5,5};
    cout<<minMoves2(listofwords);
}