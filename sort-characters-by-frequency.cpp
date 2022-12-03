  string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        vector<pair<int,char>> vp;
        for(auto i:mp){
            vp.push_back({i.second,i.first});
        }
        sort(vp.begin(),vp.end());

        string ans;
        for( auto i:vp){
            while(i.first!=0){
                ans.push_back(i.second);
                i.first--;

            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }