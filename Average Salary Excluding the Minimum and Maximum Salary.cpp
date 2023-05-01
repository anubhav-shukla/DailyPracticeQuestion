class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        return accumulate(salary.begin()+1, salary.end()-1, 0.0) / (salary.size()-2);
    }
};