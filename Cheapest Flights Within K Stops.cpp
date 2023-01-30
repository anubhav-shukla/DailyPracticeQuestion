class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> edge(100);
        for (auto& f : flights)
        {
            edge[f[0]].push_back({f[1],f[2]});
        }
        vector<int> visited(n,10000000);
        queue<vector<int>> q;
        visited[src] = 0;
        q.push({src,0,0});
        int ans = 10000000;
        while(!q.empty())
        {
            int city  = q.front()[0];
            int hop   = q.front()[2];
            int price = q.front()[1];
            q.pop();
            for (auto &e : edge[city])
            {
                if (visited[e[0]] <= price+e[1]) continue;   // better price available
                visited[e[0]] = price+e[1];                  // update base price for this ciry as hop
                if (e[0] == dst) continue;  // reach the destination (still check for better price)
                if (hop == k) continue;     // already k flights     (still check for better price)
                 q.push({e[0],visited[e[0]],hop+1});
            }            
        }
        return (visited[dst] == 10000000)?-1:visited[dst];
    }