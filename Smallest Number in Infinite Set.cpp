class SmallestInfiniteSet {
public:
    set<int>arr;
    SmallestInfiniteSet() {
        for(int i = 1 ; i <= 1000;i++)arr.insert(i);
    }
    
    int popSmallest() {
        int num = *arr.begin();
        arr.erase(arr.begin());
        return num;
    }
    
    void addBack(int num) {
        arr.insert(num);
    }
};