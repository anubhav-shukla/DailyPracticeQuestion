 bool uniqueOccurrences(vector<int>& arr) {
        
        map<int, int> mp;
        for(auto &i : arr)
            mp[i]++;
        
        set<int> st;
        for(auto &i : mp)
        {
            if(st.find(i.second) != st.end())
                return false;
            
            st.insert(i.second);
        }
        
        return true;
    }