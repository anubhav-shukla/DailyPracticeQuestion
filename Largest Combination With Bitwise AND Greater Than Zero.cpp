class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<int>bits(32,0);
        int result = INT_MIN;
        for(int bitpos=0; bitpos<32; bitpos++){
            for(auto& num:candidates){
                if(num & (1<<bitpos)){
                    bits[bitpos]++;
                }
            }
            result = max(result,bits[bitpos]);
        }
        return result;

    }
};