int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>>v1;
        vector<pair<int, int>>v2;
        
        for(int i=0; i<img1.size(); i++){
            for(int j=0; j<img2.size(); j++){
                if(img1[i][j]==1){
                    v1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    v2.push_back({i,j});
                }
            }
        }
        
        int ans=0;
        int m[60][60]={0};
        for(auto i:v1){
            for(auto j:v2){
                int x=i.first-j.first;
                int y=i.second-j.second;
                m[x+30][y+30]++;
                ans=max(ans, m[x+30][y+30]);
            }
        }
        return ans;
        
    }