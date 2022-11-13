string reverseWords(string s)
    {
        stack<string> st;
        string ans, t;
        for(auto c : s) 
        {
            if(c == ' ' or c == '\0')
            {
                if(t != "") 
                {
                    st.push(t);
                    t = "";
                }
            }
            else t += c;
        }
        if(t != "") 
            st.push(t);
        while(size(st) > 1) 
        {
            ans += st.top() + ' ';
            st.pop();
        }
        ans += st.top();
        return ans;
    }