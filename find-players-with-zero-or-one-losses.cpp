


 vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        int n=matches.size();
        unordered_map<int, int> wins;
        unordered_map<int, int> lost;
        for(auto &it: matches){
            wins[it[0]]++;
            lost[it[1]]++;
        }
        for(auto &it: wins){
            if(lost.find(it.first) == lost.end()){
                ans[0].push_back(it.first);
            }
        }
        for(auto &it: lost){
            if(it.second == 1){
                ans[1].push_back(it.first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }