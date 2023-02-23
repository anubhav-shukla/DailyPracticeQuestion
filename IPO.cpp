class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>> pq;
        int i=0;
        vector<pair<int,int>> v;
        int n=profits.size();
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        } 
        sort(v.begin(),v.end());
        // cout<<pq.size()<<endl;

        while(k){
            while(i<n&&w>=v[i].first){
               pq.push({v[i].second,v[i].first});
               i++;
            }
             if(pq.size()==0){
                 break;
             }
            auto top=pq.top();
            pq.pop();
            int p=top.first;
            int c=top.second;
            cout<<p<<" "<< c<< endl;
            w+=p;
            k--;
        }
        return w;
    }
};