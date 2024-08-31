class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;  // Adjacency list
        vector<double> result(n, 0.0);  // To store the max probability to reach each node

        // Build the adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        // Max-heap priority queue to store (probability, node)
        priority_queue<pair<double, int>> pq;

        result[start_node] = 1.0;  // Start node probability is 1
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            double currProb = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            // If we reached the end_node, return the probability
            if (currNode == end_node) {
                return currProb;
            }

            for (auto& neighbor : adj[currNode]) {
                int adjNode = neighbor.first;
                double adjProb = neighbor.second;
                
                // If we find a better probability, update it
                if (result[adjNode] < currProb * adjProb) {
                    result[adjNode] = currProb * adjProb;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }

        return result[end_node];  // Return the max probability to reach end_node
    }
};