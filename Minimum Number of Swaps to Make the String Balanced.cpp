class Solution {
public:
    int minSwaps(string s) {
        int n=s.length(),i=0;
        stack<char>st;
        while(i<n){
           if(s[i]=='[') st.push(s[i]);
           else if(st.empty()) st.push(s[i]);
           else if(st.top()=='['&&s[i]==']') st.pop();
           else st.push(s[i]);
           i++;
        }
       int ans = st.size();
        ans/=2;
        ans+=1;
        ans/=2;
        return ans;
    }
};