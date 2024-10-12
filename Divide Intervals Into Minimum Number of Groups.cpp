class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>start;
        vector<int>end;
        int n = intervals.size();

        for(int i = 0;i < n;i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int ptr = 0;
        int count = 0;

        for(auto i : start){
            if(i > end[ptr]) ptr++;
            else count++;
        }

        return count;
    }
};