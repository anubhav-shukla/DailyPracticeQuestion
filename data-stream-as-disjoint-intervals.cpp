class SummaryRanges {
private: set<int> st;
public:
    SummaryRanges() {}
    void addNum(int value) {
        st.insert(value);
    }
    vector<vector<int>> getIntervals(){       
        vector<vector<int>> result; 
        int n = size(st); 
        auto firstIt = begin(st), secondIt = begin(st);
        ++secondIt;    
        for(int i = 0; i < n ; i++) {
            int start = *firstIt;          
            while(i < n-1 && *firstIt + 1 == *secondIt) {
                i++;
                firstIt++, secondIt++;
            }
            result.push_back({start, *firstIt});
            ++firstIt, ++secondIt;
        }   
        return result;
    }
};