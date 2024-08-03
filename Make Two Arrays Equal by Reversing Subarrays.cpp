class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector <int> freq(1001,0);
        for(auto x:target){
            freq[x]++;

        }
        for(auto x1:arr){
            freq[x1]--;

        }

        for(auto y:freq){
            if(y>0)
            return false;
        }


        return true;
    }
};