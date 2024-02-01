class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> v;                                              // Make 2d array to store the 1d array of size 3   
        sort(nums.begin(), nums.end());                                 // Sort the given array                
        for (int i = 0; i + 2 < nums.size(); ++i) {                    // Iterate through the array
            if (i % 3 == 0) {                                         // Check index is multiple of 3 because we store the element in array at index =0,3,6                  
                if (nums[i + 2] - nums[i] <= k) {                    // Difference between 3rd and 2nd elements in the triplet is <= k             
                    v.push_back({nums[i], nums[i + 1], nums[i + 2]});           // If true, push 3 element together form i to i+2
                } else {
                    return {};                                          // If false, return an empty vector- no array is possible
                }
            }
        }
        return v;      // Return the array
    }
};