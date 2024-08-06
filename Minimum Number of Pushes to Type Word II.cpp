class Solution {
public:
    int minimumPushes(string word) {

        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int res=0,cnt=0;
        vector<int> freq(26,0);
        for(int i=0;i<word.size();i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end());
        for(int i=25;i>=0;i--){
            if(freq[i]>0){
            res+=freq[i]*(cnt/8 +1);
            cnt++;
            }
        }
        return res;
    }
};