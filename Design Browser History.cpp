class BrowserHistory {
public:
    vector<string>history;
    int index;  // current index

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        index = 0;    // homepage = starting page
    }
    
    void visit(string url) {
        //clear the forward history
        history.resize(index+1);
        history.push_back(url);
        index++;    //updated index
    }
    
    string back(int steps) {
        // valid previous index
        int prev = max(0,index-steps);
        index = prev;   // updated index
        return history[index];
    }
    
    string forward(int steps) {
        // valid forward index
        int next = min((int)history.size()-1, index+steps);
        index = next;
        return history[index];
    }
};