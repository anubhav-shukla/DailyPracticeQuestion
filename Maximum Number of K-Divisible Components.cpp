#define ll long long
class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<ll>sub;
    vector<int>val;
    int k;
    ll dfs(int node,int par){
      ll sum=val[node];
        for(auto it:adj[node]){
          if(it!=par){
            sum+=dfs(it,node);
          }
        }
        return sub[node]=sum;
    }
    int dfs2(int node,int par){
        int div=0;
        for(auto it:adj[node]){
            if(it==par) continue;
            if((sub[it]%k)==0) div++;
            div+=dfs2(it,node);
        }
        return div; 
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>&v, vector<int>&valu, int kp) {
        val=valu,k=kp;
    for(auto it:v){
       int x=it[0],y=it[1];
       adj[x].push_back(y),adj[y].push_back(x);
    }
        sub.resize(n,0);
        ll x=dfs(0,-1);
        return 1+dfs2(0,-1);
    }
};