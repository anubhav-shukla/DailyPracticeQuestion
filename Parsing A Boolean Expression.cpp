class Solution {
public:
    int v[20001];

    bool isOperator(char ch)
    {
        return ch == '&' || ch == '|' || ch == '!' ;
    }

    bool help(int i, int j, string &s)
    {
        if(i > j) return true;
        bool ans;
        int st = i + 2, ed = v[i+1] - 1;    // defining start and end of curr sub-expression
        bool ist = false, isf = false;   // ist = isTruePresent and isf = isFalsePresent

        for(int k = st; k<=ed; k++)
        {
            if(isOperator(s[k]))     // if char is operator then first solve that sub-expression
            {
                bool next = help(k, v[k+1] + 1, s);
                if(next) ist = true;
                else isf = true;
                k = v[k+1] + 1;     // updating value of k
            }
            else if(s[k] == 't') ist = true;
            else if(s[k] == 'f') isf = true;
        }

        if(s[i] == '&') ans = (isf == false);       // AND expression will be false if false is present
        else if(s[i] == '|') ans = (ist == true);   // OR expression will be true if true is present
        else ans = ist ? false : true;              // logic for NOT operator
        return ans;
    }

    bool parseBoolExpr(string s) {
        int n = s.size();
        memset(v, -1, sizeof(-1));
        stack<int> st;
        for(int i = 0; i<n; i++)        // storing indices of closing brackets corresponding opening ones
        {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')')
            {
                v[st.top()] = i;
                st.pop();
            }
        }
        return help(0, n-1, s);
    }
};