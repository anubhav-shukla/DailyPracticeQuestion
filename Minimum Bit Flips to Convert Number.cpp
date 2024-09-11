class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        while(start||goal){
            if(start%2==1&&goal%2==0){
                ans++;
            } else if(start%2==0&&goal%2==1){
                ans++;
            }
            start/=2;
            goal/=2;
        }
        return ans;
    }
};