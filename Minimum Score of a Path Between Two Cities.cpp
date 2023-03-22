class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        p = vector<int> (n+1, -1);
        res = vector<int> (n+1, INT_MAX);
        for(auto v : roads){
            int r = Union(v[0], v[1]);
            res[r] = min(res[r], v[2]);
        }

        if(find(1)==find(n)) return res[find(1)];
        return INT_MAX;
    }

private:
    int n;
    vector<int> p;
    vector<int> res;

    int find(int k){
        if(p[k] < 0) return k;

        return p[k] = find(p[k]);
    }

    int Union(int a, int b){
        int r1 = find(a);
        int r2 = find(b);
        int val = min(res[r1], res[r2]);
        if(r1==r2) return r1;

        if(p[r1] < p[r2]){
            p[r2] = r1;
            res[r1] = val;
            return r1;
        }
        else{
            p[r1] = r2;
            res[r2] = val;
            return r2;
        }

    }
};