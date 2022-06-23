
#include <bits/stdc++.h>
using namespace std;

int scheduleCourse(vector<vector<int>>& C) {
        sort(C.begin(), C.end(), [](auto &a, auto &b) {return a[1] < b[1];});
        priority_queue<int> pq;
        int total = 0;
        for (auto &course : C) {
            int dur = course[0], end = course[1];
            if (dur + total <= end) 
                total += dur, pq.push(dur);
            else if (pq.size() && pq.top() > dur)
                total += dur - pq.top(), pq.pop(), pq.push(dur);
        }
        return pq.size();
    }

int main(){
    vector<vector<int>> vec{ { 1, 2, 3 }, 
                         { 4, 5, 6 }, 
                         { 7, 8, 9, 4 } };
      cout<<  scheduleCourse(vec);

}