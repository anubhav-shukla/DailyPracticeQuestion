class MyCircularDeque {
public:
    int maxSize;
    deque<int> de;
    MyCircularDeque(int k) {
        maxSize = k;
    }
    
    bool insertFront(int value) {
        if(de.size() < maxSize){
        de.push_front(value);
        return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(de.size() < maxSize){
            de.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(de.size()>0){
            de.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(de.size()>0){
            de.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(de.size()>0){
            return de.front();
        }
        return -1;
    }
    
    int getRear() {
        if(de.size()>0){
            return de.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        return de.empty();
    }
    
    bool isFull() {
        return (de.size() == maxSize) ? true:false;
    }
};