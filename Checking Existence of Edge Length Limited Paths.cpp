vector<int> parent{};
vector<int> rankk{};
vector<bool> res{};
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<bool>& distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        parent.resize(n);
        rankk.resize(n);
        res.resize(q.size());
        int qcnt {};
        int eidx = 0;

        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            rankk[i] = 1;
        }

        for(auto& vi : q) {
            vi.push_back(qcnt++);
        }
        
        sort(e.begin(), e.end(), [](auto& lhs, auto& rhs) {
            return lhs[2] < rhs[2];
        });
        sort(q.begin(), q.end(), [](auto& lhs, auto& rhs) {
            return lhs[2] < rhs[2];
        });


        function<int(int)> findd = [&](int p) {
            if(parent[p] != p)
                return parent[p] = findd(parent[p]);
            return parent[p];
        };

        function<void(int,int)> unionn = [&](int x, int y) {
            int px = findd(x);
            int py = findd(y);
            if (px == py) return;
            if(rankk[px] < rankk[py]) swap(px, py);
            parent[py] = px;
            ++rankk[px];
        };


        for(auto& qele : q) {
            #define q1 qele[0]
            #define q2 qele[1]
            #define lim qele[2]
            int px = findd(q1);
            int py = findd(q2);
            for(; eidx < e.size(); ++eidx) {
                #define e1 e[eidx][0]
                #define e2 e[eidx][1]
                #define w e[eidx][2]
                if(w >= lim) break;
                unionn(e1, e2);
            }
            if(findd(q1) != findd(q2))
                res[qele[3]] = false;
            else
                res[qele[3]] = true;
        }

        return res;
    }
};