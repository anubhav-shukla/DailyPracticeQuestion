class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> query(n);

        for (int i = 0; i < n; i++) {
            query[i] = {nums[i] - k, nums[i] + k};
        }

        sort(query.begin(), query.end());

        int ans = 0;
        queue<int> q;

      
        for (auto& qu : query) {
            while (!q.empty() && q.front() < qu.first) {
                q.pop();
            }
            q.push(qu.second);
            ans = max(ans, (int)q.size());
        }
        
        return ans;
    }
};