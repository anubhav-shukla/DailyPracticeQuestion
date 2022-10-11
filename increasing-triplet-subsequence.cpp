#include<bits/stdc++.h>
using namespace std;


 bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>small_to_left(n);
        vector<int>big_to_right(n);
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini = min(mini,nums[i]);
            small_to_left[i] = mini;
            // maxi = max(maxi,nums[n-i-1]);
            // big_to_right[i]  = maxi;
        }
        
        for(int i=n-1;i>=0;i--){
            // mini = min(mini,nums[i]);
            // small_to_left[i] = mini;
            maxi = max(maxi,nums[n-i-1]);
            big_to_right[i]  = maxi;
        }
        for(int i=0;i<n;i++){
            if(small_to_left[i]!=nums[i]&& big_to_right[i]!=nums[i])
                return true;
        }
        return false;
    }

int main(){
    vector<int> num={1,2,3,4,5};
    cout<<increasingTriplet(num);
}