class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<int> pq(gifts.begin(),gifts.end());
    
        for(int i=1;i<=k;i++)
        {
            int t=pq.top();
            pq.pop();
            pq.push(sqrt(t));
        }
        
        long long sum=0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;

    }
};