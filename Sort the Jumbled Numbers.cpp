class Solution {
    int jumb(const vector<int>& mapping, int n) const {
        if (!n)
            return mapping[0];
        int output = 0;
        int e = 1;
        while (n) {
            output += mapping[n % 10] * e;
            n /= 10;
            e *= 10;
        }
        return output;
    }

public:
    vector<int>& sortJumbled(const vector<int>& mapping,
                             vector<int>& nums) const {
        vector<pair<int, int>> data(nums.size());
        for (int i = 0; i < nums.size();)
            data[i++] = {jumb(mapping, nums[i]), nums[i]};

        sort(data.begin(), data.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) -> bool{
                 return a.first < b.first;
             });
        for (int i = 0; i < nums.size();)
            nums[i++] = data[i].second;
        return nums;
    }
};