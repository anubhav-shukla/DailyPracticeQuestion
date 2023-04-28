class Solution {
public:
    void bfs(int i,vector<vector<int>>&adj,vector<int>&vis){
        queue<int>q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto it:adj[x]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        vector<vector<int>>adj(n+5);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int a=0;
                for(int k=0;k<m;k++){
                    if(strs[i][k]!=strs[j][k])a++;
                }
                if(a<=2){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){

            if(!vis[i]){
                ans++;
                bfs(i,adj,vis);
            }
        }
        return ans;

    }
};