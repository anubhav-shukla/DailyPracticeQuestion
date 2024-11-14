class Solution {
public:
    int solve(vector<int>& q, int dis, int n){
        int sum = 0;
        for(auto i : q){
            sum += (i / dis) + (i % dis != 0);
            if(sum > n)return 0;
        }
        return 1;
    }

    int minimizedMaximum(int n, vector<int>& q) {
        int l = 1, r = *max_element(q.begin(), q.end()), ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(solve(q, mid, n)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();