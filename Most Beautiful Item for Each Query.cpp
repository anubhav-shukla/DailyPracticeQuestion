class Solution {
public:

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
       vector<int>ans;

       sort(items.begin(), items.end());

       vector<int>psb;

       psb.push_back(items[0][1]);

       vector<int>psc;
       psc.push_back(items[0][0]);

       for(int i=1;i<items.size();i++) psc.push_back(items[i][0]), psb.push_back(max(psb[psb.size()-1], items[i][1]));

       psc.push_back(1e9+1);

       for(int i=0;i<queries.size();i++){
            auto it = upper_bound(psc.begin(), psc.end(), queries[i]);
            if(it==psc.end()){
                ans.push_back(0);
                continue;
            }
            int upperBoundIndex = it-psc.begin();
            upperBoundIndex--;

            if(upperBoundIndex<0){
                ans.push_back(0);
                continue;
            }

            ans.push_back(psb[upperBoundIndex]);
       }

       return ans;

    }
};