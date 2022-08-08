 #include <bits/stdc++.h>
#include <math.h>
using namespace std;


 int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }

    int main(){
        vector<int> nums ={0,1,0,3,2,3};
        cout<<lengthOfLIS(nums);
    }