#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int n){
    int prev2 = nums[0];
    int prev1 = nums[1];

    for( int i=2;i<n;i++){
        int curr = nums[i]+min(prev1,prev2);
        prev2 = prev1;
        prev1 = curr;


    }
    return min(prev1,prev2);
}
int main(){
    vector<int> nums{10,15,20};
    int n = nums.size();

    int s = solve(nums,n);
    cout<<s;
}