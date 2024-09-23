class Solution {
public:
    int res = INT_MAX;
    void dfs(vector<vector<int>>& graph,int curr,int cost = 0)
    {
        if(curr==graph.size())
        {
            res = std::min(res,cost);
            return;
        }
        if(cost>=res)
            return;
        for(auto v : graph[curr])
            dfs(graph,curr+v,cost);
        dfs(graph,curr+1,cost+1);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<vector<int>> graph(s.size());
        for(auto w:dictionary)
        {
            int start = 0;
            while(true)
            {
                if(auto pos = s.find(w,start);pos !=string::npos)
                {
                    graph[pos].push_back(w.size());
                    start = pos+1;
                }
                else
                    break;
            }
        }
        dfs(graph,0);
        return res;
    }
};