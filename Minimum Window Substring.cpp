string minWindow(string const &s, string const &t){
        if(s.size() < t.size()) return "";
        unordered_map<char, int> sm;
        unordered_map<char, int> tm;

        for(auto const &c: t) tm[c]++;
        int i = 0, j = -1, count = 0, limit = t.size();
        int minLength = INT_MAX;
        int startIndex = -1;

        while(true){
            bool sb = false, tb = false;            
		    if(minLength == 1) break;
            while(count < limit &&  i < s.size()){
                sb = true;
                char cr = s[i];
                sm[cr]++;
                if(sm[cr] <= tm[cr]) count++;
                i++;
            }

            while(count == limit && j < i){
                tb = true;
                j++;
                int temp =  i - j;
                if(minLength == INT_MAX || temp < minLength) {minLength = temp; startIndex = j; }
                char cr = s[j];
                if(sm[cr] <= tm[cr]){
                    count--;
                }
                sm[cr]--;

            }
            if(!sb && !tb) break;
        }
        if(startIndex < 0 && minLength == INT_MAX) return "";
        return s.substr(startIndex, minLength);
    }