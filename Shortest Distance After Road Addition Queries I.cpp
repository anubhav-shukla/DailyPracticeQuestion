class Solution {
public:
    int dfs( int node, vector<vector<int>>& adj, vector<int>& dist){
        if(node==adj.size()-1){
            return 0;
        }
        if(dist[node]!=INT_MAX){
            return dist[node];
        }
        for(auto nbr: adj[node]){
            dist[node] = min(dist[node], 1+dfs(nbr, adj, dist));
        }
        return dist[node];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> ans;

        for(int i=0; i<n-1; i++){
            adj[i].push_back(i+1);
        }

        for(auto q: queries){
            vector<int> dist(n, INT_MAX);
            adj[q[0]].push_back(q[1]);
            ans.push_back(dfs(0, adj, dist));
        }
        return ans;
    }
};