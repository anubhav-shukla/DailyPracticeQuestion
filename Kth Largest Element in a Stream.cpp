class KthLargest {
    int k;
    priority_queue<int,vector<int>,greater<int>> minHeap;

public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        for (auto num : nums) add(num);
    }
    
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};