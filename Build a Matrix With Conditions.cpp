
class Solution {
public:
vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        // Initialize the answer matrix, topological order vectors, adjacency lists, and indegree counts
        vector<vector<int>> ans;
        vector<int> topor; // Topological order for rows
        vector<int> topoc; // Topological order for columns
        vector<vector<int>> adjr(k); // Adjacency list for rows
        vector<vector<int>> adjc(k); // Adjacency list for columns
        vector<int> indr(k, 0); // Indegree counts for rows
        vector<int> indc(k, 0); // Indegree counts for columns
        
        // Build the adjacency list and indegree counts for rows
        for (int i = 0; i < row.size(); i++) {
            int x = row[i][0] - 1;
            int y = row[i][1] - 1;
            adjr[x].push_back(y);
            indr[y]++;
        }
        
        // Build the adjacency list and indegree counts for columns
        for (int i = 0; i < col.size(); i++) {
            int x = col[i][0] - 1;
            int y = col[i][1] - 1;
            adjc[x].push_back(y);
            indc[y]++;
        }
        
        // Perform topological sort for rows
        queue<int> q;
        for (int i = 0; i < k; i++) {
            if (indr[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int fnode = q.front();
            topor.push_back(fnode);
            q.pop();
            for (auto it : adjr[fnode]) {
                indr[it]--;
                if (indr[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // Perform topological sort for columns
        for (int i = 0; i < k; i++) {
            if (indc[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int fnode = q.front();
            topoc.push_back(fnode);
            q.pop();
            for (auto it : adjc[fnode]) {
                indc[it]--;
                if (indc[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // Check if topological sorts are valid (should have k elements)
        if (topor.size() != k || topoc.size() != k) {
            return ans; // Return empty matrix if invalid
        }
        
        // Initialize the answer matrix with zeros
        ans.resize(k, vector<int>(k, 0));
        
        // Create mappings from node to their positions in the topological order
        unordered_map<int, int> mpr;
        unordered_map<int, int> mpc;
        for (int i = 0; i < topor.size(); i++) {
            mpr[topor[i]] = i;
            mpc[topoc[i]] = i;
        }
        
        // Fill the answer matrix based on the topological order mappings
        for (int i = 0; i < k; i++) {
            int rid = mpr[i];
            int cid = mpc[i];
            ans[rid][cid] = i + 1;
        }
        
        return ans;
    }

};