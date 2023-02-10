class Solution {
public:
//app 1: using multisource BFS --> T.C : O(n*n)
    int maxDistance(vector<vector<int>>& mat) {
        int r=mat.size(),c=mat[0].size();

        int vis[r][c];
        queue<pair<int,int>> q;

        //push all land cell in queue
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                vis[i][j]=mat[i][j];

                if(mat[i][j]==1){
                    q.push({i,j});
                }
            }
        }

        //make a dir array
        pair<int,int> dir[4]= {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int dis=-1;
        while(!q.empty()){
             int n=q.size();

             while(n--){
                 //get the row and col of land cell to be processed
                 int row=q.front().first;
                 int col=q.front().second;
                 q.pop();
                 
                 //go to all 4 dir for each land cell
                 for(auto &it: dir){
                     //get new row and new col --> that we are cur visiting
                     int nr=row + it.first;
                     int nc=col + it.second;

                     //[nr,nc] cell must be 0[water cell] and not visited
                     if(nr>=0 && nc>=0 && nr<r && nc<c && vis[nr][nc]==0){
                         //push it in q, for next level traversal
                         q.push({nr,nc});
                         vis[nr][nc]=1; //mark visited
                     }
                 }
             }
             dis++;
        }
        return dis == 0 ? -1 : dis;
    }
};