class Solution {
public:
    string predictPartyVictory(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            st.push(s[i]);
            else
            {
                if(st.top()==s[i])
                st.push(s[i]);
                else
                {
                    char temp=st.top();
                    st.pop();
                    s+=temp;
                }
            }
        }
        if(st.top()=='R')
        return "Radiant";
        return "Dire";
    }
};