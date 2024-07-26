class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        for(int i=0;i<edges.size();i++){
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] == INT_MAX or dist[k][j] == INT_MAX){
                        continue;
                    }
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        pair<int,int> ans = { INT_MAX,INT_MAX};
        for(int i=0;i<n;i++){
            int curr = 0;
            for(int j=0;j<n;j++){
                if(dist[i][j] <=distanceThreshold){
                    curr++;
                }
            }
            if(curr <= ans.second ){
                ans = {i,curr};
            }
        }
        return ans.first;
    }
};