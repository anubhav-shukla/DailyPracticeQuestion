class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int zerocntback = 0;
        for(int i=n-1;i>=1;i--){
            if(s[i]=='0')zerocntback++;
        }

        int zerocntfront = (s[0]=='0') ? 1 : 0;
        int oneflipcnt = (s[0]=='1') ? 1 : 0;

        int ans = oneflipcnt + zerocntback;

        for(int i=1;i<n;i++){
            if(s[i]=='1')oneflipcnt++;
            if(s[i]=='0'){zerocntfront++;zerocntback--;}
            if(zerocntback==0){
                ans = min(ans,zerocntfront);
            }
            ans = min(ans,oneflipcnt+zerocntback);
        }
        return ans;
    }
};