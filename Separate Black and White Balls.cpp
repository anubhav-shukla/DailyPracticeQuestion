class Solution {
public:
    long long minimumSteps(string s) {
        long long left=0, right=0;
        long long swaps = 0;
        while(right < s.length()){
            if(s[right] == '0'){
                swaps += right - left;
                left++;
            }
            right++;
        }
        return swaps;
    }
};