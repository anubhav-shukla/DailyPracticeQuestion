   set<int> s;
    vector<int> v;
    RandomizedSet() {
    }  
    bool insert(int val) {
        auto it = s.find(val);
        if(it != s.end())
            return false;
        s.insert(val);
        v.push_back(val);
        return true;
    }
    bool remove(int val) {
        auto it = s.find(val);
        if(it != s.end())
        {
            s.erase(it);
            v.erase(std::remove(v.begin(), v.end(), val), v.end());
            return true;
        }
        return false;
    }
    int getRandom() {
        if(s.empty())
            return NULL;
        int idx = rand()%v.size();
        return v[idx];
    }