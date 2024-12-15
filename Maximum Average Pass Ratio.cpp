class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        
        auto pq = priority_queue<pair<double,double>, vector<pair<double,double>>, function<bool(pair<double,double> a, pair<double,double> b)>>([](pair<double,double> a, pair<double,double> b) {
            double result1 = ((a.second-a.first)*1.0)/((a.second)*(a.second+1));
            double result2 = ((b.second-b.first)*1.0)/((b.second)*(b.second+1));
            
            return result1<result2;
        });
        
        for (auto cl : classes) {
            pq.push(pair<double,double>(cl[0]*1.0, cl[1]*1.0));
        }
        
        while (extraStudents--) {
            auto cur = pq.top();
            pq.pop();
            
            cur.first++;
            cur.second++;
            pq.push(cur);
        }
        
        double result = 0;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            result += (cur.first*1.0)/cur.second;
        }
        return result/n;
    }
};