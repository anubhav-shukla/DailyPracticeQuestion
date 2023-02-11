class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>&re, vector<vector<int>>&be) {
        // we will denote red with 0  and blue with 1
        adj.resize(n);
        for(int i=0;i<re.size();i++)
        {
            int u=re[i][0];
            int v=re[i][1];
            adj[u].push_back({v,0});
        }
        for(int i=0;i<be.size();i++)
        {
            int u=be[i][0];
            int v=be[i][1];
            adj[u].push_back({v,1});
        }
        vector<int>ans;
        ans.push_back(0);
        for(int i=1;i<n;i++)
        {
            ans.push_back(bfs(i));
        }
        return ans;
    }
    int bfs(int &des)
    {
        // shortest path from source to destination
        // we will bfs for this
        // we will make a queue which will store node and color of last 
        // edge
        set<pair<int,int>>vis;
        queue<pair<int,int>>q;
        int len=0;
        q.push({0,-1});
        vis.insert({0,-1});
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int>p=q.front();
                q.pop();
                int src=p.first;
                int col=p.second;
                if(src==des)
                {
                    return len;
                }
                for(auto it=adj[src].begin();it!=adj[src].end();it++)
                {
                    pair<int,int>temp=*it;
                    int curr=temp.first;
                    int curr_col=temp.second;
                    if(col!=curr_col and vis.find({curr,curr_col})==vis.end())
                    {
                        q.push({curr,curr_col});
                        vis.insert({curr,curr_col});
                    }
                }
            }
            len++;
        }
        return -1;
    }
};