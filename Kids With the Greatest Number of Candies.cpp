class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;

        for (auto i : candies) mx = max(mx, i);

        vector<bool> ans;

        for (auto i : candies) ans.push_back(i + extraCandies >= mx ? true : false);

        return ans;
    }
};