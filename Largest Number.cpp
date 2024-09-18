class Solution {
private:
    static bool comp(const string& a, const string& b) { return a + b > b + a; }

public:
    string largestNumber(vector<int>& nums) {

        string ans = "";
        vector<string> s1;
        for(auto ele : nums)
        {
            s1.push_back(to_string(ele));
        }
        sort(s1.begin(), s1.end(), comp);
        for (auto ele : s1) {
            ans += ele;
        }
        if (ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};