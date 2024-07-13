class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> order(n);
        unordered_map<int, pair<int, char>> mp;

        for (int i = 0; i < n; i++) {
            order[i] = positions[i];
            mp[positions[i]] = {healths[i], directions[i]};
        }

        sort(positions.begin(), positions.end());
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && mp[st.top()].second == 'R' && mp[positions[i]].second == 'L') {
                if (mp[st.top()].first > mp[positions[i]].first) {
                    // Robot on the left survives
                    mp[st.top()].first -= 1;
                    mp.erase(positions[i]);
                    i++;
                } else if (mp[st.top()].first < mp[positions[i]].first) {
                    // Robot on the right survives
                    mp[positions[i]].first -= 1;
                    mp.erase(st.top());
                    st.pop();
                } else {
                    // Both robots are destroyed
                    mp.erase(st.top());
                    mp.erase(positions[i]);
                    st.pop();
                    i++;
                }
                if (i >= n) break;
            }
            if (i < n) st.push(positions[i]);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mp.find(order[i]) != mp.end()) {
                ans.push_back(mp[order[i]].first);
            }
        }

        return ans;
    }
};