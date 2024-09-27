class MyCalendarTwo {
public:
    vector<pair<int,int>> S1,S2;
    MyCalendarTwo() {
       S1.reserve(100);
       S2.reserve(100); 
    }
    
    bool book(int start, int end) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        for(auto &[s,t]:S2){
            if(max(s,start)<min(t,end)){
                return 0;
            }
        }
        for(auto &[s,t]:S1){
            int s0=max(s,start);
            int t0=min(t,end);
            if(s0<t0){
                S2.emplace_back(s0,t0);
            }
        }
            S1.emplace_back(start,end);
            return 1;
    }
};