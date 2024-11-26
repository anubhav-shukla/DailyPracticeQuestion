class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int count1=0;
        int p=-1;
        int count=0;
        for(int i=0;i<n;i++){
            count1=0;
            for(int j=0;j<edges.size();j++){
                if(edges[j][1]==i){
                    count1++;
                }
            }
            if(count1==0){
                count++;
                p=i;
            }
        }
        if(count>1){
            return -1;
        }else{
            return p;
        }
    }
};