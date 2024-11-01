class Solution {//Upvote if this solution finds you well :)
public:
    string makeFancyString(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++)
        {
            int count=1;
            ans+=s[i];
            while((i+1)<n && s[i]==s[i+1])
            {
                if(count<2)
                {
                  ans+=s[i];
                  count++ ;
                }
                i++;
            }
        }
        return ans;
    }
};