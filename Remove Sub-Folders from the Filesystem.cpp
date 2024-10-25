class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end()); // Sort folders lexicographically

        unordered_set<string> st; // To store folders without subfolders

        for (int i = 0; i < folder.size(); i++) {
            string curr = "";
            bool addFlag = true;

            for (int j = 0; j < folder[i].size(); j++) {
                curr += folder[i][j];
                // Check if current prefix exists in set and if we are at a subfolder boundary
                if (j < folder[i].size() - 1 && folder[i][j + 1] == '/') {
                    if (st.find(curr) != st.end()) {
                        addFlag = false;
                        break;
                    }
                }
            }

            // Add folder if it is not a subfolder
            if (addFlag && st.find(curr) == st.end()) {
                ans.push_back(curr);
                st.insert(curr);
            }
        }

        return ans;
    }
};