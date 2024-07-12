class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        vector<char> st;
        string top = "ab", bot = "ba";
        if(y > x){
            swap(x, y);
            swap(top, bot);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(!st.empty() && st.back() == top[0] && s[i] == top[1]){
                res += x;
                st.pop_back();
            }
            else st.push_back(s[i]);
        }
        vector<char> nst;
        for(char ch : st){
            if(ch == bot[1] && !nst.empty() && nst.back() == bot[0]){
                nst.pop_back();
                res += y;
            }
            else nst.push_back(ch);
        }
        return res;

    }
};