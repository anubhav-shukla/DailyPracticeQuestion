class Solution {
public:
    //convert function -- working is stated above
    string convert(string s)
    {
        stack<char>st;//stack of characters
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='#')
            {
                if(st.empty()) continue;// if there is nothing to remove
                else st.pop();
            }
            else
                st.push(s[i]);
        }
        string a = "";
        while(st.empty()==false)
        {
            a+=st.top();
            st.pop();
        }
        return a;
    }
    bool backspaceCompare(string s, string t) {
//convert s & t and compare them
        string s1 = convert(s);
        string s2 = convert(t);
        return s1==s2;
    }
};