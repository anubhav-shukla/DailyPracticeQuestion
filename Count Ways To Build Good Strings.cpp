class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int mod=1e9+7;
        vectordp(high+1,0);
        
        //dp[i] indicates all strings of length i;
        dp[0]=1;  // always as one null("") string will be present in every case
       
        
        // Iterate over each length `i`.
        for(int i=1;i=zero){
                dp[i]+=dp[i-zero];
            }
            if(i>=one){
                dp[i]+=dp[i-one];
            }
            dp[i]%=mod;
        }
        
        // Add up the number of strings with each valid length [low ~ high].
        int answer=0;
        for(int i=low;i<=high;i++){
            answer+=dp[i];
            answer%=mod;
        }
        
        return answer;     
    }
};