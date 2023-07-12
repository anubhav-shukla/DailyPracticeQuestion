class Solution {
public:
    bool DFS(int s, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& dfsVisited, vector<bool>& checkCycle) {
        visited[s] = dfsVisited[s] = true; // Mark the current node as visited and in the current DFS path
        for (auto it : graph[s]) {
            if (!visited[it]) { // If the adjacent node is not visited
                if (DFS(it, graph, visited, dfsVisited, checkCycle))
                    return checkCycle[s] = true; // If a cycle is detected, mark the current node as part of a cycle
            } else if (dfsVisited[it]) { // If the adjacent node is visited and in the current DFS path
                return checkCycle[s] = true; // A cycle is detected, mark the current node as part of a cycle
            }
        }
        dfsVisited[s] = false; // Mark the current node as not visited in the current DFS path
        return false; // No cycle detected, current node is safe
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<bool> visited(v), dfsVisited(v), checkCycle(v);
        vector<int> ans;
        for (int i = 0; i < v; i++) {
            if (!visited[i])
                DFS(i, graph, visited, dfsVisited, checkCycle);
        }
        for (int i = 0; i < v; i++) {
            if (!checkCycle[i])
                ans.push_back(i); // Add the nodes that are not part of any cycle (eventual safe nodes) to the result
        }
        return ans;
    }
};