class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n, 0);
        vector<vector<int>> reverseGraph(n);

        // Build reverse graph and calculate outdegree
        for (int node = 0; node < n; node++) {
            for (int neighbor : graph[node]) {
                reverseGraph[neighbor].push_back(node);
                outdegree[node]++;
            }
        }
        queue<int> bfsQueue;
        // Enqueue nodes with outdegree = 0
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                bfsQueue.push(i);
            }
        }

        // Process nodes in BFS manner, reducing outdegree of predecessors
        while (!bfsQueue.empty()) {
            int current = bfsQueue.front();
            bfsQueue.pop();

            for (int prev : reverseGraph[current]) {
                outdegree[prev]--;
                if (outdegree[prev] == 0) {
                    bfsQueue.push(prev);
                }
            }
        }

        // Gather all nodes that have outdegree 0 after processing
        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                safeNodes.push_back(i);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
