class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int> > > adj;

        for(auto x: connections){
            int u = x[0];
            int v = x[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        queue<int> q;
        int ans = 0;
        q.push(0);
        vector<int>visited(n,0);
        while(!q.empty()){
            int f = q.front();
            q.pop();
            visited[f] = 1;
            for(auto x: adj[f]){
                if(!visited[x.first]){
                    ans+=x.second;
                    q.push(x.first);
                    visited[x.first] = 1;
                }
            }
        }
        return ans;
    }
};