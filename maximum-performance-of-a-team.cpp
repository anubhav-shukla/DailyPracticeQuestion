int mod = 1e9+7;
class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] > b[0];
    }
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> eff_sp;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i =0; i < n; i ++)
            eff_sp.push_back({efficiency[i], speed[i]});
        
        sort(eff_sp.begin(), eff_sp.end(), cmp);
        long perf = 0, sum = 0;     ;
        for(auto es : eff_sp){
          
            if(pq.size() == k){
                sum -= pq.top();
                pq.pop();
            }
            pq.push(es[1]);
            sum = (sum+es[1]);
            perf = max(perf, (sum * es[0]));
        }
        return perf%mod;
    }
};