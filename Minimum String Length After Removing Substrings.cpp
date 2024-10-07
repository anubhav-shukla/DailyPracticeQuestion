class Solution {
public:
    int minLength(string s) {
        int size = s.length();
        string stk="";
        for(int i=0;i<size;i++){
            if(!stk.empty() && (stk.back()=='C' && s[i]=='D')){
                stk.pop_back();
            }
            else if(!stk.empty() && (stk.back()=='A' && s[i]=='B')){
                stk.pop_back();
            }
            else stk.push_back(s[i]);
        }
        return stk.size();
    }
};