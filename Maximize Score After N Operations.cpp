class Solution {
public:
    int n;
    int f(vector<int>&nums, vector<bool>&visited, int op, unordered_map<vector<bool>, int>& mp){
        if(mp.find(visited)!=mp.end()){
            return mp[visited];
        }
        int maxScr=0;
        for(int i=0; i<=n-2; i++){
            if(visited[i]==true) continue;
            for(int j=i+1; j<n; j++){
                if(visited[j]==true) continue;

                visited[i]=true;
                visited[j]=true;
                int currentScore=op* __gcd(nums[i], nums[j]);
                int remainScore= f(nums, visited, op+1, mp);
                maxScr=max(maxScr, currentScore+remainScore);
                visited[i]=false;
                visited[j]=false;
            }
        }
        return mp[visited]=maxScr;
    }

    int maxScore(vector<int>& nums) {
        n=nums.size();
        vector<bool>visited(n, false);
        unordered_map<vector<bool>,int>mp;
        return f(nums, visited, 1, mp);


    }
};