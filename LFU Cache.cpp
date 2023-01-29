class LFUCache {
public:
    LFUCache(int capacity) : cap(capacity){}
    int get(int key) {
        if(mem.count(key)==0) return -1;
        
        increaseFreq(key);
        return mem[key].first;
    }
    void put(int key, int value) {
        if(cap==0) return;
        if(mem.count(key)){ //update value and count
            increaseFreq(key);
            mem[key].first = value;
        }
        else{
            if(size<cap){ //insert new key
                size++;
                leastFreq = 1;
                mem[key] = {value, 1};
                freq[1].push(key);
            }
            else{ //erase least freq
                eraseLeastFreq();
                leastFreq = 1;
                mem[key] = {value, 1};
                freq[1].push(key);
            }
        }
    }
    void increaseFreq(int key){
        int count = mem[key].second;
        if(freq[count].front()==key){
            freq[count].pop();
        }
        if(freq[count].empty()){
            if(leastFreq==count) leastFreq++;
            freq.erase(count);
        }
        count++;
        freq[count].push(key);
        mem[key].second++;
    }
    void eraseLeastFreq(){
        int eraseKey = freq[leastFreq].front();
        while(leastFreq!=mem[eraseKey].second){
            freq[leastFreq].pop();
            while(freq[leastFreq].empty()){
                freq.erase(leastFreq);
                leastFreq++;
            }
            eraseKey = freq[leastFreq].front();
        }
        freq[leastFreq].pop();
        if(freq[leastFreq].empty()) freq.erase(leastFreq);
        //we don't need to find next leastFreq since it will be set to 1
        mem.erase(eraseKey);
    }
private:
    int cap;
    int size = 0;
    int leastFreq = 1;
    unordered_map<int, pair<int, int>> mem; //key: val, count
    unordered_map<int, queue<int>> freq; //count: key
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */