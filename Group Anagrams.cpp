vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> answer;
		
        for(auto str:strs){
            string s = str;
            sort(str.begin(),str.end());
            mp[str].push_back(s);
        }
        for(auto &[_,ans]:mp) answer.push_back(ans);
        
        return answer;
    }