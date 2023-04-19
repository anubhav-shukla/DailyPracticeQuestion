class Solution {
public:
    //Dp and Memoization Solution,gets Accepted✅    
    int mod=1e9+7;
    int dp[1000][1001];   
    int find(int id,vector<vector<int>>& fre,string& target,int col,int n,int m){
        if(id==n){
            return 1;
        }
        if(col==m){
            return 0;
        }
        if(dp[id][col]!=-1){
            return dp[id][col];
        }
        int not_pick=find(id,fre,target,col+1,n,m);
        int pick=0;
        if(fre[col][target[id]-'a']!=0){
            int curr=fre[col][target[id]-'a'];
            pick=(((long)curr*(long)find(id+1,fre,target,col+1,n,m)%mod)%mod)%mod;
        }
        return dp[id][col]=(pick +not_pick)%mod;
    }
    int numWays(vector<string>& words, string target) {
        memset(dp,-1,sizeof(dp));
        int n=target.size(),m=words[0].size();
        vector<vector<int>> fre(m,vector<int>(26,0));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                fre[j][words[i][j]-'a']++;
            }
        }
        return find(0,fre,target,0,n,m);
    }
};