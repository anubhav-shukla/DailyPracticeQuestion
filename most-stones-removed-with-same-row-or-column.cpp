



vector<int> rank, parent;
    int find(int a) {
        if(a == parent[a])
            return a;
        return parent[a] = find(parent[a]);
    }
    void Union(int a, int b) {
        int x = find(a), y = find(b);
        if(x != y) {
            if(rank[x] > rank[y]) 
                parent[y] = x;
            else if(rank[x] < rank[y]) 
                parent[x] = y;
            else {
                parent[y] = x;
                rank[x] += 1;
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0, res = 0;
        for(auto i : stones) {
            maxRow = max(maxRow, i[0]);
            maxCol = max(maxCol, i[1]);
        }
        int n = maxRow + maxCol + 2;
        rank.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; i++)
            rank[i] = 0;
        for(int i = 0; i < n; i++)
            parent[i] = i;
        unordered_set<int> st;
        for(auto it : stones) {
            int a = it[0], b = it[1] + maxRow + 1;
            Union(a, b);
            st.insert(a);
            st.insert(b);
        }
        for(auto i : st) {
            if(find(i) == i)
                res++;
        }
        return stones.size() - res;
    }

