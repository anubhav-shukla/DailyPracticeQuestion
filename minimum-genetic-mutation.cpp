unordered_map<string, int> visited; 
    int countStringDifference(string &s1, string &s2, int len){
        int result = 0;
        for(int i=0;i<len;i++){
            if(s1[i] != s2[i]) result++;
        }
        return result;
    }
    int getNextStringIndex(string &curr, int steps, string &final, vector<string>& bank){
        if(countStringDifference(curr, final, 8) == 0) return steps;
        int minm = INT_MAX;
        visited[curr] = 1;
        for(int i=0;i<bank.size();i++){
            if(countStringDifference(curr, bank[i], 8) == 1 && visited[bank[i]] != 1) minm = min(minm, getNextStringIndex(bank[i], steps+1, final, bank));
        }
        visited[curr] = 0;
        return minm;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int response = getNextStringIndex(start, 0, end, bank);
        return response == INT_MAX ? -1 : response;
    }