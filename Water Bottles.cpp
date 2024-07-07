class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int empty=numBottles;
        while(empty>=numExchange){
             int t=empty/numExchange;
             ans+=t;
             empty=empty%numExchange;
             empty+=t;

        }
        return ans;

        
        
    }
};