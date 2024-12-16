class Solution {
public:
    class comparator {
    public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        }
    };
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            pq.push({nums[i], i});
        }
        
        for(int i = 0; i<k; i++) {
            auto [min, idx] = pq.top(); pq.pop();
            pq.push({multiplier*min, idx});
        }
        
        vector<int> output(n, 0);
        while(!pq.empty()) {
            auto [val, i] = pq.top(); pq.pop();
            output[i] = val;
        }
        return output;
    }
};