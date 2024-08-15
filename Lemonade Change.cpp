class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five =0;
        int ten =0;
        for(auto i : bills){
            if(i==5){
                five++;

            }
            else if(i ==10){
                if(five>0){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                if(ten >0 && five>0){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five -=3;

                }
                else{
                    return false;
                }
            }
        }
        return true;


    }
};