bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if(N == 1) return true;
        unordered_map<int, int> g;
        deque<vector<int>> con (dislikes.begin(), dislikes.end());
        g[con.front()[0]] = 1;
        g[con.front()[1]] = 2;
        con.pop_front();
        while(!con.empty()){
            vector<int> temp = con.front();
            con.pop_front();
            if(g.find(temp[0]) == g.end() && g.find(temp[1]) == g.end()){
                con.push_back(temp);
            }
            else if(g.find(temp[0]) == g.end() && g.find(temp[1]) != g.end()){
                g[temp[0]] = g[temp[1]] == 1 ? 2 : 1; 
            }
            else if(g.find(temp[0]) != g.end() && g.find(temp[1]) == g.end()){
                g[temp[1]] = g[temp[0]] == 1 ? 2 : 1; 
            }
            else{
                if(g[temp[0]] == g[temp[1]]) {
                    return false;
                }
            }
        }
        return true;
    }