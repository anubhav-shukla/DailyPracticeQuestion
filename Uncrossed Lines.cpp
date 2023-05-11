class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>v(n+1,vector<int>(m+1));
        for(int i=0;i<m+1;i++){
            v[0][i]=0;
        }
        for(int i=0;i<n+1;i++){
            v[i][0]=0;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(nums1[i-1]==nums2[j-1]){
                    v[i][j]=v[i-1][j-1]+1;
                
                }
                else{
                    v[i][j]=max(v[i-1][j],v[i][j-1]);
                    
                }
            }
        }
        return v[n][m];
    }
};