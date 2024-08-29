class Solution {
public:
    void dfs(vector<vector<int>>& stones,vector<bool>&vis, int in ){
        vis[in] = true;
        // Yha pe visited mark krdia jisse ek hi bar use hua ek coordinate
        for(int i=0; i<stones.size(); i++){
            // Piche agr bich m koi rh gya h toh wo bhi cover ho jayega agr vsited nhi toh
    if(vis[i] == false && (stones[i][0] == stones[in][0] ||stones[i][1] == stones[in][1])){
                dfs(stones,vis,i);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool>vis(n,false);

        int count= 0;
        for(int i=0; i<n; i++){
            if(vis[i] == true){
                continue;
            }
            dfs(stones,vis,i);
            count++;
        }
        return n-count;
    }
};