class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int tfa = times[targetFriend][0];
        priority_queue<int,vector<int>,greater<int>>available; //chair_index
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>reserved;//departure_time,chair_index
        sort(times.begin(),times.end());
        for(auto t:times){
            while(!reserved.empty() && reserved.top().first<=t[0]){
                 available.push(reserved.top().second);
                 reserved.pop();
            }
            if(t[0]==tfa) break;
            if(available.empty()) reserved.push({t[1],reserved.size()});
            else{
                reserved.push({t[1],available.top()});
                available.pop();
            }
        }
        return available.empty()?reserved.size():available.top();
    }
};