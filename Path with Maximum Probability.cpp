class Solution {
public:
    void dfs(vector<vector<pair<int, double>>>& graph, vector<bool>& vis, int src, int dst, double curres, double& res, double& mn) {
        if (curres <= mn)
            return;
        if (src == dst) {
            res = max(res, curres);
            return;
        }
        vis[src] = true;
        for (const auto& cur : graph[src]) {
            int newSrc = cur.first;  
            double newSrcProb = cur.second; 
            if (!vis[newSrc] && curres * newSrcProb >= res)
                dfs(graph, vis, newSrc, dst, curres * newSrcProb, res, mn);
        }
        vis[src] = false;  
    }

    double maxProbability(int n, vector<vector<int>>& e, vector<double>& succProb, int src, int dst) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < e.size(); i++) {
            graph[e[i][0]].push_back( { e[i][1], succProb[i] } );
            graph[e[i][1]].push_back( { e[i][0], succProb[i] } );
        }
        vector<bool> vis(n, false);  
        double res = 0, mn = 1e-5;
        dfs(graph, vis, src, dst, 1.0, res, mn);
        return res;
    }
};