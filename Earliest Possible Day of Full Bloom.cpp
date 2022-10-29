int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        vector<pair<int, int>> pairs(n);
        int rest_base = 0;
        for (int i = 0; i < n; i++){
            pairs[i] = {growTime[i], plantTime[i]};
            rest_base += plantTime[i];
        }
        int base = rest_base;
        sort(pairs.rbegin(), pairs.rend());
        int max_external = 0;
        for (int i = 0; i < n; i++){
           
            rest_base -= pairs[i].second;
            int rest_day = pairs[i].first;
            if (rest_day <= rest_base)
                continue;
            
            max_external = max(max_external, rest_day - rest_base);
        }
        return base + max_external;
    }