



  priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    bool even=true;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        even=!even;
        if(!even)
        {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        else
        {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(!even)
            return minHeap.top();
        else
            return (maxHeap.top()+minHeap.top())/2.0;
    }