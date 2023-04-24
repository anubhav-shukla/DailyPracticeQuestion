class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n=stones.size();
        for(int i=0;i<n;i++) pq.push(stones[i]);
        while(pq.size()>1){
            int d=pq.top();
            pq.pop();
            int g=pq.top();
            pq.pop();
            if(d!=g) pq.push(d-g);
        }
        if(pq.size()==0) return 0;
        return pq.top();
    }
};