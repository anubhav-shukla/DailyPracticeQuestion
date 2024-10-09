class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        stack<char>st;
        int i=0;
        while(i<n){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(st.top()=='('&&s[i]==')'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        int ans = st.size();
        return ans;
    }
};