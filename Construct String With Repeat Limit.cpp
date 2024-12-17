class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> counter(26, 0);
        for(auto ch : s) {
            counter[ch-'a']++;
        }
        
        queue<char> q;
        for (int i=25;i>=0; i--) {
            if (counter[i] != 0) q.push('a'+i);
        }
        
        string answer = "";
        while(!q.empty()) {
            auto topper = q.front();
            q.pop();
            while (counter[topper-'a'] != 0) {
                if (counter[topper-'a'] > repeatLimit) {
                    answer.append(repeatLimit, topper);
                    counter[topper-'a'] -= repeatLimit;
                    if (q.empty()) break;
                    answer.push_back(q.front());
                    counter[q.front()-'a']--;
                    if (counter[q.front()-'a'] == 0) q.pop();
                } else {
                    answer.append(counter[topper-'a'], topper);
                    counter[topper-'a'] = 0;
                }
            }
        }
        
        return answer;
    }
};