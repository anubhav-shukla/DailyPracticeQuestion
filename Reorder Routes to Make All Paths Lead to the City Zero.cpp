class Solution {
public:
   int minReorder(int n, vector<vector<int>>& c) {
        vector<vector<int>>adj(n);
        vector<vector<int>>v(n);
        for(int i=0;i<c.size();i++){
            int u=c[i][0];
            int x=c[i][1];
            adj[u].push_back(x);
            adj[x].push_back(u);
            v[u].push_back(x);
        }
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        int count=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto i:adj[x]){
                bool f=false;
                if(!vis[i]){
                q.push(i);
                
                for(int j=0;j<v[i].size();j++){
                    if(v[i][j]==x)
                        f=true;
                }
                if(!f)
                    count++;
                vis[i]=true;}
            }
        }
        return count;
    }
};